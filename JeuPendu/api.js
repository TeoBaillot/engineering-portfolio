const fs = require("fs");
const url = require("url");
let listeMotsValides = [];
let erreur = 0;
let nombreErreurMax = 6;
let motADecouvrir = "";
let lettresDecouvertes = [];
let lettresTestees = [];
let difficulteMin = {
    "facile": 4,
    "moyen": 6,
    "difficile": 8
}
let difficulteMax = {
    "facile": 5,
    "moyen": 8,
    "difficile": 12
}

fs.readFile("./lesmiserables.txt", (erreur, texte) => {
    let listeMots = texte.toString().split(/[(\r?\n),. ]/);
    for (let mot of listeMots) {
        let valide = true;
        for (let i = 0; i < mot.length; i++) {
            if (mot.charCodeAt(i) < 97 || mot.charCodeAt(i) > 122) {
                valide = false;
                break;
            }
        }
        if (valide) {
            for (let i = listeMotsValides.length; i <= mot.length; i++) {
                listeMotsValides.push([]);
            }
            listeMotsValides[mot.length].push(mot);
        }
    }
});

function manageRequest(request, response) {
    let url = request.url.split("?");
    let chemin = url[0].split("/");
    let etoile = chemin[2];
    let urlParse = new URL(request.url, request.protocol + "://" + request.headers.host);
    let difficulte = urlParse.searchParams.get("level") ?? "moyen";
    let max = parseInt(urlParse.searchParams.get("maxLetters") ?? difficulteMax[difficulte]);
    let min = parseInt(urlParse.searchParams.get("minLetters") ?? difficulteMin[difficulte]);
    let lettreEntree = urlParse.searchParams.get("letter");
    let bonneLettre = null;

    if (min > max) {
        response.statusCode = 400;
        response.end(`le minimum est supÃ©rieur au maximum`);
        return;
    }
    if (etoile === "getWord") {
        response.statusCode = 200;
        let tailleMot = Math.floor(Math.random() * (max - min)) + min;
        response.end(listeMotsValides[tailleMot][Math.floor(Math.random() * listeMotsValides[tailleMot].length)]);
    } else if (etoile === "newGame") {
        erreur = 0;
        lettresTestees = [];
        let tailleMot = Math.floor(Math.random() * (max - min)) + min;
        response.statusCode = 200;
        motADecouvrir = listeMotsValides[tailleMot][Math.floor(Math.random() * listeMotsValides[tailleMot].length)];
        lettresDecouvertes = Array(tailleMot).fill("_");
        response.statusCode = 200;
        response.setHeader("Content-Type", "application/json");
        response.end(JSON.stringify({
            "message": "partie creee",
            "taille": motADecouvrir.length,
            "lettresDecouvertes": lettresDecouvertes,
            "nombreErreur": erreur,
            "lettreEntree": lettreEntree,
            "lettresTestees": lettresTestees,
            "bonneLettre": bonneLettre,
            "nombreErreurMax": nombreErreurMax
        }));
    } else if (etoile === "testLetter") {
        if (lettresTestees.includes(lettreEntree)) {
            response.setHeader("Content-Type", "application/json");
            response.end(JSON.stringify({
                "message": "la lettre est deja testée",
                "taille": motADecouvrir.length,
                "lettresDecouvertes": lettresDecouvertes,
                "nombreErreur": erreur,
                "lettreEntree": lettreEntree,
                "lettresTestees": lettresTestees,
                "bonneLettre": bonneLettre,
                "nombreErreurMax": nombreErreurMax,
            }));
            return;
        }
        lettresTestees.push(lettreEntree);
        if (motADecouvrir.includes(lettreEntree)) {
            bonneLettre = true;
            for (let i = 0; i < motADecouvrir.length; i++) {
                if (motADecouvrir[i] === lettreEntree) {
                    lettresDecouvertes[i] = lettreEntree;
                }
            }
        } else {
            bonneLettre = false;
            erreur++;
            if (erreur >= nombreErreurMax) {
                response.statusCode = 200;
                response.setHeader("Content-Type", "application/json");
                response.end(JSON.stringify({
                    "message": "perdu",
                    "taille": motADecouvrir.length,
                    "lettresDecouvertes": lettresDecouvertes,
                    "nombreErreur": erreur,
                    "lettreEntree": lettreEntree,
                    "lettresTestees": lettresTestees,
                    "bonneLettre": bonneLettre,
                    "nombreErreurMax": nombreErreurMax,
                    "mot": motADecouvrir
                }));
                return;
            }
            response.statusCode = 200;
            response.setHeader("Content-Type", "application/json");
            response.end(JSON.stringify({
                "message": "la lettre est pas dans le mot",
                "taille": motADecouvrir.length,
                "lettresDecouvertes": lettresDecouvertes,
                "nombreErreur": erreur,
                "lettreEntree": lettreEntree,
                "lettresTestees": lettresTestees,
                "bonneLettre": bonneLettre,
                "nombreErreurMax": nombreErreurMax
            }));
            return;
        }
        if (!lettresDecouvertes.includes("_")) {
            response.statusCode = 200;
            response.setHeader("Content-Type", "application/json");
            response.end(JSON.stringify({
                "message": "gagne",
                "taille": motADecouvrir.length,
                "lettresDecouvertes": lettresDecouvertes,
                "nombreErreur": erreur,
                "lettreEntree": lettreEntree,
                "lettresTestees": lettresTestees,
                "bonneLettre": bonneLettre,
                "nombreErreurMax": nombreErreurMax,
                "mot": motADecouvrir
            }))
            return;
        }
        response.statusCode = 200;
        response.setHeader("Content-Type", "application/json");
        response.end(JSON.stringify({
            "message": "une lettre est testee",
            "taille": motADecouvrir.length,
            "lettresDecouvertes": lettresDecouvertes,
            "nombreErreur": erreur,
            "lettreEntree": lettreEntree,
            "lettresTestees": lettresTestees,
            "bonneLettre": bonneLettre,
            "nombreErreurMax": nombreErreurMax
        }));
    } else {
        response.statusCode = 404;
        response.end(`Erreur ${request.url}`);
    }
}

exports.manage = manageRequest;
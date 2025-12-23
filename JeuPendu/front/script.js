let alphabet = 'abcdefghijklmnopqrstuvwxyz'.split('');

async function nouvellePartie(boolean, resultat) {
    //initialise la partie
    let difficulte;
    if (!boolean) {
        difficulte = document.getElementById("choixDifficulte2").value;
    } else if (resultat === "gagne") {
        difficulte = document.getElementById("choixDifficulte6").value;
    } else {
        difficulte = document.getElementById("choixDifficulte4").value;
    }
    document.getElementById("inputTexte").removeAttribute("disabled");
    let main = document.querySelector("main");
    main.classList.add("notDisplayed");
    document.getElementById("choixDifficulte2").classList.add("notDisplayed");
    let chargement = document.getElementById("chargement");
    JOUER.classList.add("notDisplayed");
    chargement.classList.remove("notDisplayed");
    document.querySelector("aside").classList.add("notDisplayed");

    let reponse = await reponseServeur("newGame?level=" + difficulte);
    let tailleMot = reponse["taille"];
    let nombreErreurMax = reponse["nombreErreurMax"];
    let lettresDecouvertes = reponse["lettresDecouvertes"];
    let erreur = reponse["nombreErreur"];

    //affichage du début de la partie et du pendu
    let elementToBeDisplayed = document.getElementsByClassName("notDisplayed");
    while (elementToBeDisplayed.length) {
        elementToBeDisplayed[0].classList.remove("notDisplayed");
    }
    chargement.classList.add('notDisplayed');
    for (let partieBonhomme of document.getElementsByClassName("bonhomme")) {
        partieBonhomme.classList.add("notDisplayed");
    }
    document.getElementById("JOUER").classList.add("notDisplayed");
    document.getElementById("gagne").classList.add("notDisplayed");
    document.getElementById("perdu").classList.add("notDisplayed");
    document.getElementById("choixDifficulte2").classList.add("notDisplayed");


    //clavier
    let lettres = document.getElementById("lettres");
    while (lettres.childElementCount > 1) {
        lettres.lastElementChild.remove();
    }
    for (let lettre of alphabet) {
        let element = document.getElementById("lettre-template").content.cloneNode(true);
        element.firstElementChild.firstElementChild.innerText = lettre;
        element.firstElementChild.id = "lettre-" + lettre;
        lettres.appendChild(element);
    }
    //stats
    let nombreErreurs = document.getElementById("erreur");
    nombreErreurs.innerText = erreur;
    let essaisRestants = document.getElementById("essaisRestants");
    essaisRestants.innerText = (nombreErreurMax - erreur).toString();

    //affichage du mot
    let motAAfficher = document.getElementById("mot");
    motAAfficher.innerText = lettresDecouvertes.join(" ");

    //boutons rejouer
    let REJOUER = document.getElementById("REJOUER");
    REJOUER.addEventListener("click", () => nouvellePartie(true, "gagne"));
    let REJOUER1 = document.getElementById("REJOUER1");
    REJOUER1.addEventListener("click", () => nouvellePartie(true, "perdu"));
}

async function estCliquee() {
    let zoneDeTexte = document.getElementById("inputTexte");
    zoneDeTexte.focus();
    let lettreEntree = zoneDeTexte.value.toString().toLowerCase();
    let reponseTestLetter = await reponseServeur("testLetter?letter=" + lettreEntree);
    let nombreErreurMax = reponseTestLetter["nombreErreurMax"];
    let lettresDecouvertes = reponseTestLetter["lettresDecouvertes"];
    let bonneLettre = reponseTestLetter["bonneLettre"];
    zoneDeTexte.value = "";
    let motAAfficher = document.getElementById("mot");
    if (bonneLettre !== null) {
        if (bonneLettre) {
            document.getElementById("lettre-" + lettreEntree).classList.add("bonneLettre");
            motAAfficher.innerText = lettresDecouvertes.join(" ");
        } else {
            document.getElementById("lettre-" + lettreEntree).classList.add("mauvaiseLettre");
            nombreErreurs = document.getElementById("erreur");
            nombreErreurs.innerText = reponseTestLetter["nombreErreur"];
            let essaisRestants = document.getElementById("essaisRestants");
            essaisRestants.innerText = (nombreErreurMax - reponseTestLetter["nombreErreur"]).toString();
            document.querySelector("#pendu > .notDisplayed").classList.remove("notDisplayed");
        }
    }
    if (reponseTestLetter["message"] === "perdu") {
        let perdu = document.getElementById("perdu");
        perdu.classList.remove("notDisplayed");
        motAAfficher.innerText = reponseTestLetter["mot"];
        zoneDeTexte.setAttribute("disabled", true);
    }

    if (reponseTestLetter["message"] === "gagne") {
        let gagne = document.getElementById("gagne");
        gagne.classList.remove("notDisplayed");
        zoneDeTexte.setAttribute("disabled", true);
    }
}

async function reponseServeur(endpoint) {
    let reponse = await fetch("/api/" + endpoint);
    if (reponse.ok) {
        return JSON.parse(await reponse.text());
    } else {
        return await reponseServeur(endpoint);
    }
}

let JOUER = document.getElementById("JOUER");
JOUER.addEventListener("click", nouvellePartie);

var TESTER = document.getElementById("TESTER");
TESTER.addEventListener("click", estCliquee);
document.getElementById("inputTexte")
    .addEventListener("keyup", async function (event) {
        if (event.key === "Enter") {
            await estCliquee();
        }
    });
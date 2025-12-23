const http = require("http");
const files = require("./files");
const api = require("./api");

const serveur = http.createServer((requete, reponse) => {
    let listeRequete = requete.url.split("/");
    if (listeRequete[1] === "api") {
        api.manage(requete, reponse);
    } else {
        files.manage(requete, reponse);
    }
});

serveur.listen(8000, "0.0.0.0", () => {
    console.log("Nickel");
});
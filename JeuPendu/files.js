const url = require("url");
const path = require("path");
const fs = require("fs");
const chemin = "./front";
const mimeTypes = {
    '.ico': 'image/x-icon',
    '.html': 'text/html',
    '.js': 'text/javascript',
    '.json': 'application/json',
    '.css': 'text/css',
    '.png': 'image/png',
    '.jpg': 'image/jpeg',
    '.wav': 'audio/wav',
    '.mp3': 'audio/mpeg',
    '.svg': 'image/svg+xml',
    '.pdf': 'application/pdf',
    '.doc': 'application/msword',
    '.md': 'text/plain',
    'default': 'application/octet-stream'
};

function manageRequest(request, response) {
    let parser = url.parse(request.url);
    let pathname = chemin + parser.pathname;
    if (pathname.includes("..")){
        response.statusCode = 400;
        response.end(`Vous avez essayé de m'avoir ${request.url}`);
        return;
    }
    fs.exists(pathname, (exists) => {
        if (exists) {
            fs.readFile(pathname, (error, data) => {
                if (error) {
                    response.statusCode = 500;
                    response.end(`erreur de lecture ${request.url}`);
                } else {
                    response.statusCode=200;
                    response.setHeader("Content-type", mimeTypes[path.extname(pathname)] ?? mimeTypes.default);
                    response.end(data);
                }
            })
        } else {
            response.statusCode = 404;
            response.end(`Le fichier n'existe pas ${request.url}`);
        }
    })
}

exports.manage = manageRequest;
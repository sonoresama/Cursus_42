const fs = require('fs');
const path = require('path');

function customMiddleware(req, res, next) {
  const requestedPath = path.join(__dirname, req.url);
  
  // Check if the requested file exists
  fs.access(requestedPath, fs.constants.F_OK, (err) => {
    if (err) {
      // If the file doesn't exist, serve index.html
      const indexPath = path.join(__dirname, 'index.html');
      fs.readFile(indexPath, 'utf8', (err, data) => {
        if (err) {
          console.error(`Error reading index.html: ${err}`);
          res.writeHead(500);
          res.end('Internal Server Error');
        } else {
          res.writeHead(200, { 'Content-Type': 'text/html' });
          res.end(data);
        }
      });
    } else {
      // If the file exists, proceed with normal handling
      next();
    }
  });
}

module.exports = customMiddleware;

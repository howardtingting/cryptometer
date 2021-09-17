const server = require('./app.js')

const port = process.env.PORT || 3000;

const host = '0.0.0.0'; //MUST be 0.0.0.0 for docker; 127.0.0.1 otherwise

server.listen(port, host, () => {
  console.log(`Listening on ${host}:${port}...`);
});

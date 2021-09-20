const server = require('./app.js')

const port = process.env.PORT || 3000;
const host = process.env.HOST || "127.0.0.1";

server.listen(port, host, () => {
  console.log(`Listening on ${host}:${port}...`);
});

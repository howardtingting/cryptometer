const md5 = require('./md5');
const sha1 = require('./sha1');
const sha3 = require('./sha3');
const sha256 = require('./sha3');
const crc32 = require('./crc32');
const keccak = require('./keccak');

module.exports = {
  md5: md5,
  sha1: sha1,
  sha3: sha3,
  sha256: sha256,
  crc32: crc32,
  keccak: keccak
};

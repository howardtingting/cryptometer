//FOLLOWS the MD5 algorithm as derived from https://en.wikipedia.org/wiki/MD5#Algorithm
const sha3cc = require('../../build/Release/sha3cc');

const sha3fn = sha3cc();

const processInputStr = function(inputStr) {
  //Check inputStr is valid str
  //Return as valid string if not
  return inputStr;
}

const sha3 = function(inputStr) {
  //convert inputObj to str
  //if file, set up fs read, read string in chunks, concatenate, then hash
  console.log(`Calling sha3 on \'${processInputStr(inputStr)}\'`);
  return sha3fn(inputStr);
}

module.exports = sha3;

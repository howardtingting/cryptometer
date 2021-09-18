//FOLLOWS the MD5 algorithm as derived from https://en.wikipedia.org/wiki/MD5#Algorithm
const sha256cc = require('../../build/Release/sha256cc');

const sha256fn = sha256cc();

const processInputStr = function(inputStr) {
  //Check inputStr is valid str
  //Return as valid string if not
  return inputStr;
}

const sha256 = function(inputStr) {
  //convert inputObj to str
  //if file, set up fs read, read string in chunks, concatenate, then hash
  console.log(`Calling sha256 on \'${processInputStr(inputStr)}\'`);
  return sha256fn(inputStr);
}

module.exports = sha256;

//FOLLOWS the MD5 algorithm as derived from https://en.wikipedia.org/wiki/MD5#Algorithm
const keccakcc = require('../../build/Release/keccakcc');

const keccakfn = keccakcc();

const processInputStr = function(inputStr) {
  //Check inputStr is valid str
  //Return as valid string if not
  return inputStr;
}

const keccak = function(inputStr) {
  //convert inputObj to str
  //if file, set up fs read, read string in chunks, concatenate, then hash
  console.log(`Calling keccak on \'${processInputStr(inputStr)}\'`);
  return keccakfn(inputStr);
}

module.exports = keccak;

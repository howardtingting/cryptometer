console.log("seg?")
const hash_fns = require('../crypto_fns/hash_fns/hash_fns.js');
console.log("seg")
validFns = {
  "md5": true,
  "sha1": true,
  "sha3": true,
  "sha256": true,
  "crc32": true,
  "keccak": true
};

exports.checkHashfn = (req, res, next, val) => {
  const hashfnStr = req.params.hashfn;
  if (!(hashfnStr in validFns)) {
    console.log("failed hashfn")
    return res.status(404).json({
      status: 'fail',
      message: `Invalid hashing function: ${hashfnStr}`
    });
  }
  next();
}

exports.prepareInput = (req, res, next, val) => {
  const input = req.body.input;
  const isFile = req.body.isFile;
  req.body.input = req.body.input ? req.body.input : 'default string';
  req.body.isFile = req.body.isFile ? true : false;
  next();
}

exports.hash = (req, res) => {
  //whitelist req.params.hashfn values using middleware
  const hashfnStr = req.params.hashfn;
  const hashfn = hash_fns[hashfnStr];

  const isFile = req.body.isFile; //treat input as file object

  const hashVal = hashfn(req.body.input, isFile);
  res.status(200).json({
    status: 'success',
    message: `hash function ${hashfnStr} called`,
    body: req.body,
    hashfn: req.params.hashfn,
    hash: hashVal
  });
}

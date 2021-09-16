const hash_fns = require('../crypto_fns/hash_fns/hash_fns.js');

validFns = {"md5": true, "sha1": true, "sha2": true};

exports.checkHashfn = (req, res, next, val) => {
  const hashfnStr = req.params.hashfn;
  req.body.input = req.body.input ? req.body.input : 'default string';
  if (!(hashfnStr in validFns)) {
    console.log("failed hashfn")
    return res.status(404).json({
      status: 'fail',
      message: `Invalid hashing function: ${hashfnStr}`
    });
  }
  next();
}

exports.hash = (req, res) => {
  //whitelist req.params.hashfn values using middleware
  const hashfnStr = req.params.hashfn;
  const hashfn = hash_fns[hashfnStr];
  const hashVal = hashfn(req.body.input);
  res.status(200).json({
    status: 'success',
    message: `hash function ${hashfnStr} called`,
    body: req.body,
    hashfn: req.params.hashfn,
    hash: hashVal
  });
}

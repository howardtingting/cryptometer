exports.encrypt = (req, res) => {
  //req.params.encryptfn
  //req.body
  res.status(200).json({
    status: 'success',
    message: 'encrypt function called',
    body: req.params.encryptfn
  });
}

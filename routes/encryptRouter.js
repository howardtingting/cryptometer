const router = require('express').Router();

const encryptController = require('../controllers/encryptController.js');

router.route('/:encryptfn')
  .get(encryptController.encrypt)

module.exports = router;

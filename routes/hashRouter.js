const router = require('express').Router();

const hashController = require('../controllers/hashController.js');

router.param('hashfn', hashController.checkHashfn);
router.param('hashfn', hashController.prepareInput);

router.route('/:hashfn')
  .get(hashController.hash)

module.exports = router;

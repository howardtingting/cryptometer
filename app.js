const express = require('express');

const hashRouter = require('./routes/hashRouter.js');
const encryptRouter = require('./routes/encryptRouter.js');

const app = express();

//1. Middleware
if (process.env.NODE_ENV === 'development') {
  const morgan = require('morgan');
  app.use(morgan('dev'));
  console.log('Running development server.');
} else {
  console.log('Running production server.');
}
app.use(express.json());

//2. routes
app.use('/api/v1/hash', hashRouter);
app.use('/api/v1/encrypt', encryptRouter);

module.exports = app;

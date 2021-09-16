hashbabbler
========

[![NPM Package][npm]][npm-url]
[![Build Size][build-size]][build-size-url]
[![NPM Downloads][npm-downloads]][npmtrends-url]
[![Language Grade][lgtm]][lgtm-url]

#### String Hashing API ####

API to hash strings.

### Usage ###

1. git clone <URL>
#####In Project Folder#####
2. npm install
3. npm run start:dev
#####Sample fetch from browser#####
```javascript
const input = "Value to be hashed";

const hashVal = fetch("http://localhost:3000/api/v1/hash/md5", {
  //...
  body: { input: input }
  //...
})
.then(res => res.json())
.then(data => data.hash)
.catch((err) => {
  //error handling
});
```

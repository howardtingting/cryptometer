hashbabbler
========

#### String Hashing API ####

API to hash strings via different hashing algorithms (e.g. md, sha, etc.)

### Usage Demo ###

##### In Terminal #####
1. git clone https://github.com/howardtingting/hashbabbler.git

##### In Project Folder #####
2. npm install
3. npm run start:dev

##### Alternative Installation (with Docker) #####
2. docker-compose up -d --build #this runs the server immediately
##### to shut down the server: #####
3. docker-compose down -v


##### Sample fetch from browser #####
```javascript
const input = "Value to be hashed";

//To call other hashing functions, replace hash/md5 with hash/${fn}
//example: fetch("http://localhost:3000/api/v1/hash/sha1", ...
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

### The Real API ###

##### ...in progress... #####

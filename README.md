
hashbabbler
========

#### String Hashing API ####

API to hash strings via different hashing algorithms (e.g. md, sha, etc.)

### Usage Demo ###

##### 1. In Terminal #####
```console
user:~$ git clone https://github.com/howardtingting/hashbabbler.git
user:~/Hashbabbler$ npm install
user:~/Hashbabbler$ npm run start:dev
```
```console
##### 2. Alternative (with Docker) #####
user:~$ git clone https://github.com/howardtingting/hashbabbler.git
user:~/Hashbabbler$ docker-compose up -d --build #runs the server
user:~/Hashbabbler$ docker-compose down #shuts down the server
```
```console
##### 3. Alternative (Pull image from Dockerhub) #####
user:~$ docker pull howardtingting/hashbabbler
user:~$ docker run --name hashbabble -d -p 3000:3000 howardtingting/hashbabbler
```
See https://hub.docker.com/repository/docker/howardtingting/hashbabbler

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

##### ...in progress; whitelisting for personal apps... #####

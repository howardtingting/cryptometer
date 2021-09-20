FROM ubuntu:20.04

RUN apt-get update \
 && apt-get upgrade -y \
 && apt-get install -y libnode-dev

RUN apt-get install -y nodejs \
 && apt-get install -y npm

RUN mkdir /hashbabbler

WORKDIR /hashbabbler

COPY ./package.json /hashbabbler

RUN npm install --force

RUN npm clean-install

CMD ["node-gyp", "configure", "build"]

COPY . /hashbabbler

EXPOSE 3000

CMD [ "npm", "run", "start:docker" ]

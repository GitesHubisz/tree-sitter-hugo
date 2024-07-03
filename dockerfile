FROM node:14

ENV NODE_DIR /usr/local

ENV PATH $NODE_DIR/bin:$PATH

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . /.git/ *

RUN npm run build

CMD ["npm", "run", "build"]
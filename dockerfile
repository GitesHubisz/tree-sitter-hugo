FROM ubuntu:20.04 as builder

WORKDIR /app

ENV DEBIAN_FRONTEND noninteractive

RUN apt update -qq && apt install -yqq nodejs npm

COPY package*.json ./

RUN npm install --force

COPY . .

RUN mkdir -p /app/dist
RUN npm install tree-sitter-cli --force

RUN npm run build

FROM ubuntu:20.04

WORKDIR /app

COPY --from=builder /app/dist .

CMD ["node", "index.js"]
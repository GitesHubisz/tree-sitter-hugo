FROM ubuntu:20.04 as builder

WORKDIR /app

ENV DEBIAN_FRONTEND noninteractive

RUN apt update -qq && apt install -yqq curl && \
    curl -fsSL https://deb.nodesource.com/setup_16.x | bash - && \
    apt install -yqq nodejs python3

COPY package*.json ./

RUN npm install --force

COPY . .

RUN npm install tree-sitter-cli --force

RUN mkdir -p /app/dist
RUN npm run build

FROM ubuntu:20.04

WORKDIR /app

COPY --from=builder /app/dist .

RUN apt update -qq && apt install -yqq curl && \
    curl -fsSL https://deb.nodesource.com/setup_16.x | bash - && \
    apt install -yqq nodejs

CMD ["node", "index.js"]
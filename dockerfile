FROM node:14-buster AS build

# Zainstaluj narzędzia do kompilacji
RUN apt-get update && apt-get install -y build-essential git

# Sklonuj repozytorium (lub skopiuj pliki lokalnie)
WORKDIR /app
COPY . /app

# Buduj parser
# Zakładam, że masz skrypty w package.json dla tych zadań
RUN npm install && npm run build

# Uruchomienie
FROM node:14-buster
COPY --from=build /app /app
WORKDIR /app

# Instalacja Tree-sitter CLI globalnie
RUN npm install -g tree-sitter-cli

# Eksponuj port dla playground
EXPOSE 8080

# Uruchom playground
CMD ["tree-sitter", "playground"]
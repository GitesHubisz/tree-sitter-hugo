# Etap budowy
FROM node:16-buster AS build

# Zainstaluj narzędzia do kompilacji (możliwe, że potrzebne do budowy zależności npm)
RUN apt-get update && apt-get install -y build-essential git

# Skopiuj pliki projektu
WORKDIR /app
COPY . .

# Instaluj zależności i buduj
RUN npm install && npm run build

# Etap uruchomieniowy
FROM node:16-buster
COPY --from=build /app /app
WORKDIR /app

# Instalacja zależności tylko do uruchomienia, jeśli to konieczne
# RUN npm install --only=production

# Eksponuj port serwera, jeśli masz aplikację nasłuchującą na tym porcie
# EXPOSE 8080

# Ustawienie komendy uruchomieniowej
CMD ["npm", "start"] # Lub coś innego, co uruchamia Twoją aplikację
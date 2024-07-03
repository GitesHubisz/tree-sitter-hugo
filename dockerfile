# Use a Node.js image to run the build
FROM node:14

# Install tree-sitter CLI globally with unsafe permissions
RUN npm install -g tree-sitter-cli --unsafe-perm

# Create app directory and copy content
WORKDIR /app
COPY . .

# Build the parsers
WORKDIR /app/tree-sitter-html
RUN tree-sitter generate
WORKDIR /app/tree-sitter-go-template
RUN tree-sitter generate
WORKDIR /app/tree-sitter-hugo
RUN tree-sitter generate

# Build the combined parser
WORKDIR /app
RUN tree-sitter build-wasm
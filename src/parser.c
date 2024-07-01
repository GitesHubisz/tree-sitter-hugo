#include <tree_sitter/parser.h>
#include "../tree-sitter-html/src/parser.c"
#include "../tree-sitter-go-template/src/parser.c"
#include <wctype.h>

// Enum for external tokens
enum TokenType {
  HUGO_DOUBLE_BRACE_OPEN,
  HUGO_DOUBLE_BRACE_CLOSE,
};

// External scanner functions
void *tree_sitter_hugo_external_scanner_create() {
  return NULL;
}

bool tree_sitter_hugo_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  // Implement scanning logic for Hugo double brace tokens
  return false;
}

unsigned tree_sitter_hugo_external_scanner_serialize(void *payload,
                                                     char *buffer) {
  return 0;
}

void tree_sitter_hugo_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {}

void tree_sitter_hugo_external_scanner_destroy(void *payload) {}
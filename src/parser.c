#include <tree_sitter/parser.h>
#include "../tree-sitter-html/src/parser.c"
#include "../tree-sitter-go-template/src/parser.c"

enum TokenType {
  HTML_TOKEN,
  GO_TEMPLATE_TOKEN,
  HUGO_DOUBLE_BRACE_OPEN,
  HUGO_DOUBLE_BRACE_CLOSE
};

void *tree_sitter_hugo_external_scanner_create() {
  return NULL; // Initialize combined scanner
}

void tree_sitter_hugo_external_scanner_destroy(void *payload) {
  // Clean up combined scanner
}

unsigned tree_sitter_hugo_external_scanner_serialize(void *payload, char *buffer) {
  // Serialize combined scanner state
  return 0;
}

void tree_sitter_hugo_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  // Deserialize combined scanner state
}

bool tree_sitter_hugo_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  if (valid_symbols[HUGO_DOUBLE_BRACE_OPEN] && lexer->lookahead == '{' && lexer->lookahead == '{') {
    lexer->advance(lexer, false);
    lexer->advance(lexer, false);
    lexer->result_symbol = HUGO_DOUBLE_BRACE_OPEN;
    return true;
  }

  if (valid_symbols[HUGO_DOUBLE_BRACE_CLOSE] && lexer->lookahead == '}' && lexer->lookahead == '}') {
    lexer->advance(lexer, false);
    lexer->advance(lexer, false);
    lexer->result_symbol = HUGO_DOUBLE_BRACE_CLOSE;
    return true;
  }

  // Add scanning logic for HTML and Go templates by invoking their scanners

  return false;
}

extern "C" {
  // Export the parser's external scanner functions
  void *tree_sitter_html_external_scanner_create();
  void tree_sitter_html_external_scanner_destroy(void *);
  bool tree_sitter_html_external_scanner_scan(void *, TSLexer *, const bool *);
  unsigned tree_sitter_html_external_scanner_serialize(void *, char *);
  void tree_sitter_html_external_scanner_deserialize(void *, const char *, unsigned);

  void *tree_sitter_go_template_external_scanner_create();
  void tree_sitter_go_template_external_scanner_destroy(void *);
  bool tree_sitter_go_template_external_scanner_scan(void *, TSLexer *, const bool *);
  unsigned tree_sitter_go_template_external_scanner_serialize(void *, char *);
  void tree_sitter_go_template_external_scanner_deserialize(void *, const char *, unsigned);

  void *tree_sitter_hugo_external_scanner_create();
  void tree_sitter_hugo_external_scanner_destroy(void *);
  bool tree_sitter_hugo_external_scanner_scan(void *, TSLexer *, const bool *);
  unsigned tree_sitter_hugo_external_scanner_serialize(void *, char *);
  void tree_sitter_hugo_external_scanner_deserialize(void *, const char *, unsigned);
}

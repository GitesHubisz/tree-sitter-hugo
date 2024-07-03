#include <tree_sitter/parser.h>
#include <wctype.h>
#include "../tree-sitter-html/src/parser.c"

// Add Go Template rules
void* go_template_rule(void* root) {
    // Create a new node for the Go Template element
    void* node = tsparse_create_node(TS_NODE_GO_TEMPLATE, NULL);
    // Set the parent of the node to the root node
    tsparse_set_parent(node, root);
    return node;
}

void* go_template_param_rule(void* node) {
    // Create a new node for the Go Template parameter
    void* param_node = tsparse_create_node(TS_NODE_GO_TEMPLATE_PARAM, NULL);
    // Set the parent of the node to the current node
    tsparse_set_parent(param_node, node);
    return param_node;
}

// Add Hugo-specific rules
void* hugo_param_rule(void* root) {
    // Create a new node for the Hugo parameter
    void* param_node = tsparse_create_node(TS_NODE_HUGO_PARAM, NULL);
    // Set the parent of the node to the root node
    tsparse_set_parent(param_node, root);
    return param_node;
}

void* hugo_file_rule(void* node) {
    // Create a new node for the Hugo file
    void* file_node = tsparse_create_node(TS_NODE_HUGO_FILE, NULL);
    // Set the parent of the node to the current node
    tsparse_set_parent(file_node, node);
    return file_node;
}

// Update the parser's rules table with the new Go Template and Hugo-specific rules
void tree_sitter_hugo_parser_init(void) {
    // ...
    tsparse_add_rule("go_template", go_template_rule);
    tsparse_add_rule("go_template_param", go_template_param_rule);
    tsparse_add_rule("hugo_param", hugo_param_rule);
    tsparse_add_rule("hugo_file", hugo_file_rule);
}

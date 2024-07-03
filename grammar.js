module.exports = grammar(require('tree-sitter-html/grammar'), {
  name: 'hugo',

  // Rozszerz gramatykę HTML o nowe reguły
  extras: ($, original) => original.concat([/[\s\uFEFF\u2060\u200B\u00A0]+/]),

  rules: {
    // Dodaj nową regułę dla Hugo
    hugo_template: $ => seq(
      '{{',
      repeat(/[^}]/),
      '}}'
    ),

    // Rozszerz istniejącą regułę, np. `text`, o Hugo
    text: ($, original) => choice(original, $.hugo_template),
  }
});
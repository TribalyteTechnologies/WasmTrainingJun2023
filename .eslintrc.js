module.exports = {
  'env': {
    'browser': true,
    'es2021': true,
  },
  extends: [
    "eslint:recommended" 
  ],
  'overrides': [
  ],
  "ignorePatterns": ["main.js","*.test.js",".eslintrc.js","*.config.js","*cy.js"],
  'parserOptions': {
    'ecmaVersion': 'latest',
  },
  'rules': {
    "no-unused-vars": "off",
    "no-undef": "off",
    "semi": [ "error", "always" ]
  },
};

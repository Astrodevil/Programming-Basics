// CheckPascalCase method checks the given string is in PascalCase or not.

const checkPascalCase = VarName => {
  // firstly, check that input is a string or not.
  if (typeof VarName !== 'string') {
    return 'not a string.'
  }

  const reg = /^[A-Z][A-Za-z]*$/
  return reg.test(VarName)
}

console.log(checkPascalCase('myVar'))
console.log(checkPascalCase('MyVar'))
console.log(checkPascalCase('my-var'))

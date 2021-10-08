// CheckCamelCase method checks the given string is in camelCase or not.

const checkCamelCase = varName => {
  // firstly, check that input is a string or not.
  if (typeof varName !== 'string') {
    return 'not a string.'
  }

  const reg = /^[a-z][A-Za-z]*$/
  return reg.test(varName)
}

console.log(checkCamelCase('myVar'))
console.log(checkCamelCase('MyVar'))
console.log(checkCamelCase('my-var'))

// CheckKebabCase method checks the given string is in kebab-case or not.

const checkSnakeCase = varName => {
  // firstly, check that input is a string or not.
  if (typeof varName !== 'string') {
    return 'not a string.'
  }

  const reg = /(.*?)-([a-zA-Z])*/
  return reg.test(varName)
}

console.log(checkSnakeCase('myVar'))
console.log(checkSnakeCase('my_var'))
console.log(checkSnakeCase('my-var'))

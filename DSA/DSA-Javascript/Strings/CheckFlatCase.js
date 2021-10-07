// checkFlatCase method checks if the given string is in flatcase or not.

const checkFlatCase = varname => {
  // firstly, check that input is a string or not.
  if (typeof varname !== 'string') {
    return 'not a string.'
  }

  const reg = /^[a-z]*$/
  return reg.test(varname)
}

console.log(checkFlatCase('myvar'))
console.log(checkFlatCase('MyVar'))
console.log(checkFlatCase('my-var'))

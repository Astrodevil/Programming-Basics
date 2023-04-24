// factorial method returns the factorial of a number
const factorial = (n) => {
  // firstly, check that input is a number or not.
  if (typeof n !== 'number') {
    return 'not a number.'
  }
  return n <= 1 ? 1 : n * factorial(n - 1)
}

console.log(factorial(5))

// Return the factorial of a number

const factorial = num => {
  if (typeof num !== 'number') {
    return 'Not a number'
  } else {
    if (num === 0 || num === 1) {
      return 1
    } else if (num < 0) {
      return 'negative numbers has no factorial'
    } else {
      return num * factorial(num - 1)
    }
  }
}

console.log(factorial(-4))
console.log(factorial(8))
console.log(factorial('hello world'))
console.log(factorial(4))

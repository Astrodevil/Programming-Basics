// gdc method returns the greatest common divisor between two numbers
const gcd = (a, b) => {
  // firstly, check that input is a number or not.
  if (typeof a !== 'number' || typeof b !== 'number') {
    return 'invalid argument, not a number.'
  }
  return b === 0 ? a : gcd(b, a % b)
}

console.log(gcd(10, 15))

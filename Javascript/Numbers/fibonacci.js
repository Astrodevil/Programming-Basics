// fibonacci method returns the specific Nth fibonacci number
const fibonacci = (n, memo = {}) => {
  // firstly, check that input is a number or not.
  if (typeof n !== 'number') {
    return 'not a number.'
  }
  return (
    memo[n] ||
    (n <= 2 ? 1 : (memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)))
  )
}

console.log(fibonacci(20))

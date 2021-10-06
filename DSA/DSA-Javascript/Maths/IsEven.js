// Return true if a number is even

const isEven = num => {
  if (typeof num !== 'number') return 'not a number'
  return num % 2 === 0
}

console.log(isEven(2))
console.log(isEven('hello world'))
console.log(isEven(9))

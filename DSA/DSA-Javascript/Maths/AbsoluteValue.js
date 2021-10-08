// Return the absolute value of a given number

const absoluteValue = value => {
  return value < 0 ? -value : value
}

console.log(absoluteValue(-10))
console.log(absoluteValue(23))
console.log(absoluteValue(0))

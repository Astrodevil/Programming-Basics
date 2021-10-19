// Return the fibonacci numbers.

const fibonacci = nth => {
  const sequence = []

  if (nth >= 1) sequence.push(1)
  if (nth >= 2) sequence.push(1)

  for (let i = 2; i < nth; i++) {
    sequence.push(sequence[i - 1] + sequence[i - 2])
  }

  return sequence
}

console.log(fibonacci(-3))
console.log(fibonacci(5))
console.log(fibonacci(7))

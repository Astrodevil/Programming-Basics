// Reverse a given string

function reverseString (string) {
  if (typeof string !== 'string') {
    return 'not a string.'
  }
  let reversedString = ''
  let index

  for (index = string.length - 1; index >= 0; index--) {
    reversedString += string[index]
  }

  return reversedString
}

console.log(reverseString('hello'))
console.log(reverseString(100))
console.log(reverseString('world'))

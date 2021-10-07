// Palindrome check is case sensitive; i.e. Aba is not a palindrome

const checkPalindrome = str => {
  // check that input is a string
  if (typeof str !== 'string') {
    return 'Not a string'
  }
  if (str.length === 0) {
    return 'Empty string'
  }
  // Reverse only works with array, thus convert the string to array, reverse it and convert back to string
  // return as palindrome if the reversed string is equal to the input string
  const reversed = [...str].reverse().join('')
  return str === reversed ? 'Palindrome' : 'Not a Palindrome'
}

console.log(checkPalindrome('hello'))
console.log(checkPalindrome(12))
console.log(checkPalindrome(null))
console.log(checkPalindrome(undefined))
console.log(checkPalindrome('level'))

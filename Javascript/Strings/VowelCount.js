// Given a string of words or phrases, count the number of vowels.

const vowelCount = value => {
  if (typeof value !== 'string') {
    return 'not a string'
  }
  const vowels = ['a', 'e', 'i', 'o', 'u']

  let countVowels = 0

  for (let i = 0; i < value.length; i++) {
    const char = value[i].toLowerCase()
    if (vowels.includes(char)) {
      countVowels++
    }
  }
  return countVowels
}

console.log(vowelCount('hello'))
console.log(vowelCount('rythm'))
console.log(vowelCount(20))
console.log(vowelCount(null))

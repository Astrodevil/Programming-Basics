const bubbleSort = inputArr => {
  const len = inputArr.length
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len; j++) {
      if (inputArr[j] > inputArr[j + 1]) {
        const tmp = inputArr[j]
        inputArr[j] = inputArr[j + 1]
        inputArr[j + 1] = tmp
      }
    }
  }
  return inputArr
}

const array = [51, 76, 17, 8, 10, 2, 121, 44]
const sortedArray = bubbleSort(array)
console.log(sortedArray) // [ 2,  8, 10,  17, 44, 51, 76, 121 ]

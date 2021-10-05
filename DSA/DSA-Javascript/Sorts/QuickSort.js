function quickSort (items) {
  const length = items.length

  if (length <= 1) {
    return items
  }
  const PIVOT = items[0]
  const GREATER = []
  const LESSER = []

  for (let i = 1; i < length; i++) {
    if (items[i] > PIVOT) {
      GREATER.push(items[i])
    } else {
      LESSER.push(items[i])
    }
  }

  let sorted = quickSort(LESSER)
  sorted.push(PIVOT)
  sorted = sorted.concat(quickSort(GREATER))

  return sorted
}

const array = [10, 57, 3, 27, 2]
const sortedArray = quickSort(array)
console.log(sortedArray) // [ 2, 3, 10, 27, 57 ]

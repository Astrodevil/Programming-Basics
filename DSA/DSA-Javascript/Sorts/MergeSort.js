// Sort and merge two given arrays
function merge (list1, list2) {
  const results = []
  let i = 0
  let j = 0

  while (i < list1.length && j < list2.length) {
    if (list1[i] < list2[j]) {
      results.push(list1[i++])
    } else {
      results.push(list2[j++])
    }
  }

  return results.concat(list1.slice(i), list2.slice(j))
}

// Break down the lists into smaller pieces to be merged
function mergeSort (list) {
  if (list.length < 2) return list

  const listHalf = Math.floor(list.length / 2)
  const subList1 = list.slice(0, listHalf)
  const subList2 = list.slice(listHalf, list.length)

  return merge(mergeSort(subList1), mergeSort(subList2))
}

// Merge Sort Example
const unsortedArray = [90, 56, 32, 81, 27, 6, 4, 17, 19, 10]
const sortedArray = mergeSort(unsortedArray)

console.log(sortedArray) // [ 4,  6, 10, 17, 19, 27, 32, 56, 81, 90 ]

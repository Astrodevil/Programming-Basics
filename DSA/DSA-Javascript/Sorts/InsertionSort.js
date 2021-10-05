function insertionSort (unsortedList) {
  const len = unsortedList.length
  for (let i = 1; i < len; i++) {
    let j
    const tmp = unsortedList[i] // Copy of the current element.
    // Check through the sorted part and compare with the number in tmp. If large, shift the number
    for (j = i - 1; j >= 0 && unsortedList[j] > tmp; j--) {
      // Shift the number
      unsortedList[j + 1] = unsortedList[j]
    }
    // Insert the copied number at the correct position in sorted part.
    unsortedList[j + 1] = tmp
  }
}

const arr = [57, 32, 16, 2, 46, 89, 43, 88]
insertionSort(arr)
console.log(arr) // [ 2, 16, 32, 43, 46, 57, 88, 89 ]

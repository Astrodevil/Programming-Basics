/* Queue
 * A queue is an ordered list of elements where an element is inserted at the end
 * of the queue and is removed from the front of the queue.
 */

class Queue {
  constructor () {
    this.items = []
  }

  enqueue (element) {
    // Adds an element to the queue
    this.items.push(element)
  }

  dequeue () {
    // Removes an element from the queue
    try {
      if (this.isEmpty()) {
        throw new Error('Underflow')
      }
      return this.items.shift()
    } catch (err) {
      console.log(err.message)
    }
  }

  peek () {
    // returns the front element of the queue without removing it.
    try {
      if (this.isEmpty()) {
        throw new Error('No elements in Queue')
      }
      return this.items[0]
    } catch (err) {
      console.log(err.message)
    }
  }

  length () {
    // Returns the length of the queue
    if (this.isEmpty()) return 'No elements in Queue'
    return this.items.length
  }

  isEmpty () {
    // Returns true if the queue is empty
    return this.items.length === 0
  }

  clear () {
    // Remove all item in the queue
    this.items = []
  }
}

// Implementation
const myQueue = new Queue()
myQueue.enqueue(1)
myQueue.enqueue(5)
myQueue.enqueue(76)
myQueue.enqueue(69)
myQueue.enqueue(32)

console.log(myQueue.length()) // 5

console.log(myQueue.items) // [ 1, 5, 76, 69, 32 ]

console.log(myQueue.dequeue()) // 1
console.log(myQueue.length()) // 4

console.log(myQueue.peek()) // 5

console.log(myQueue.isEmpty()) // false

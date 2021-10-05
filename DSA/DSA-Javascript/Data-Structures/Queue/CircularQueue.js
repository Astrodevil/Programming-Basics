/* Circular Queue
 * offer a quick to store FIFO data with a maximum size.
 * Conserves memory as we only store up to our capacity
 * It is opposed to a queue which could continue to grow if input outpaces output
 * Doesn't use dynamic memory so No memory
 */

class CircularQueue {
  constructor (size) {
    this.element = []
    this.size = size
    this.maxLength = 0
    this.front = 0
    this.back = -1
  }

  enqueue (element) {
    // Adds an element to the queue
    try {
      if (this.maxLength >= this.size) {
        throw new Error('Maximum length exceeded')
      }
      this.back++
      this.element[this.back % this.size] = element
      this.maxLength++
    } catch (err) {
      console.log(err.message)
    }
  }

  dequeue () {
    // Removes an element from the queue
    try {
      if (this.isEmpty()) {
        throw new Error('No elements in Queue')
      }
      const value = this.peek()
      this.element[this.front % this.size] = null
      this.front++
      this.maxLength--
      return value
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
      return this.element[this.front % this.size]
    } catch (err) {
      console.log(err.message)
    }
  }

  length () {
    // Returns the length of the queue
    if (this.isEmpty()) return 'No elements in Queue'
    return this.element.length
  }

  clear () {
    // Remove all item in the queue
    this.element = []
    this.maxLength = 0
    this.back = 0
    this.front = -1
  }

  isEmpty () {
    // Returns true if the queue is empty
    return this.length === 0
  }
}

// Implementation
const queue = new CircularQueue(6) // Enter Max Length
queue.enqueue(1)
queue.enqueue(15)
queue.enqueue(176)
queue.enqueue(59)
queue.enqueue(3)
queue.enqueue(55)

console.log(queue.length()) // 6

console.log(queue.element) // [ 1, 15, 176, 59, 3, 55 ]

console.log(queue.dequeue()) // 1
console.log(queue.length()) // 6

console.log(queue.peek()) // 15

console.log(queue.isEmpty()) // false

queue.enqueue(39)
queue.enqueue(85)

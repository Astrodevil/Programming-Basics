/* Stack
 * A stack is exactly what it sounds like. An element gets added to the top of
 * the stack and only the element on the top may be removed. This is an example
 * of an array implementation of a Stack. So an element can only be added/removed
 * from the end of the array.
 */

class Stack {
  constructor () {
    this.items = []
  }

  push (el) {
    // push element into the items
    this.items.push(el)
  }

  pop () {
    // Removes an element from the stack, if the function is call on an empty stack it indicates "Underflow"
    if (this.items.length === 0) return 'Underflow'
    return this.items.pop()
  }

  peek () {
    // Returns the top most elements in the stack, but doesn't delete it
    return this.items[this.items.length - 1]
  }

  isEmpty () {
    // Return true if stack is empty
    return this.items.length === 0
  }
}

// Implementation
const myStack = new Stack()

myStack.push(1)
myStack.push(5)
myStack.push(76)
myStack.push(69)
myStack.push(32)
myStack.push(54)

console.log(myStack.peek()) // 54

console.log(myStack.pop()) // 54

console.log(myStack.items) // [ 1, 5, 76, 69, 32 ]

console.log(myStack.peek()) // 32

myStack.push(55)

console.log(myStack.peek()) // 55

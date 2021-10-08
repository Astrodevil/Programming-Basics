# Find fibonacci number with given index
def fibonacci(idx):
    if idx < 0:
        print("Index can not be less than 0")
    # First fibonacci Number = 0
    elif idx == 0:
        return 0
    # Second fibonacci Number = 1
    elif idx == 1:
        return 1
        # Next fibonacci number is sum of previous two fibonacci numbers
    else:
        return fibonacci(idx-1) + fibonacci(idx-2)


index = int(input("Enter index: "))
print(fibonacci(index))

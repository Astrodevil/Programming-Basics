def binary_search(arr, x):
    left = 0
    right = len(arr) - 1
    mid = 0
    while left <= right:
        mid = (left + right) // 2
        # If x is greater, ignore left half
        if arr[mid] < x:
            left = mid + 1
        # If x is smaller, ignore right half
        elif arr[mid] > x:
            right = mid - 1
        # means x is present at mid
        else:
            return mid
    # If we reach here, then the element was not present
    return -1


arr = [2, 3, 5, 7, 9, 10, 11]
x = 10

result = binary_search(arr, x)
if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")

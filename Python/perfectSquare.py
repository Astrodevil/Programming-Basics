# Check if a number is perfect square using binary search.

def perfect_square(n: int) -> bool:
    try:
        left = 0
        right = n
        while left <= right:
            mid = (left + right) // 2
            if mid ** 2 == n:
                return True
            elif mid ** 2 > n:
                right = mid - 1
            else:
                left = mid + 1
        return False
    except Exception as error:
        return error


print(perfect_square(16))
print(perfect_square(1))
print(perfect_square(10))
print(perfect_square(None))
print(perfect_square([]))

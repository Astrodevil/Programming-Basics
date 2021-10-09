# Check if a number is a perfect cube or not.
def perfect_cube(n: int) -> bool:
    val = n ** (1 / 3)
    return (val * val * val) == n


print(perfect_cube(27))
print(perfect_cube(4))

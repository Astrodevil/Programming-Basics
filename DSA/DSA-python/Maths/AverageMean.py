# Find mean of a list of numbers.

def mean(nums: list) -> float:
    try:
        if not nums:
            raise ValueError("List is empty")
        return sum(nums) / len(nums)
    except Exception as err:
        return err


print(mean([3, 6, 9, 12, 15, 18, 21]))
print(mean([5, 10, 15, 20, 25, 30, 35]))
print(mean([1, 2, 3, 4, 5, 6, 7, 8]))
print(mean([]))

# Find Minimum Number in a List
def find_min(nums):
    min_num = nums[0]
    for num in nums:
        if min_num > num:
            min_num = num
    return min_num


print(find_min([0, 1, 2, 3, 4, 5, -3, 24, -56]))
print(find_min([46, 32, -10, -54, 100, 101, -127]))

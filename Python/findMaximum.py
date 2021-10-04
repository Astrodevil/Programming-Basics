# Find Maximum number in a list
def find_max(nums):
    maximum_num = nums[0]
    for num in nums:
        if num > maximum_num:
            maximum_num = num
    return maximum_num


print(find_max([2, 4, 9, 7, 19, 94, 5]))

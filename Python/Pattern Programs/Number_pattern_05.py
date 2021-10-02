# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# 1
# 11
# 121
# 1221

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())
if n == 0:
    print()
else:
    print(1)
i = 1
while i < n:
    j = 0
    while j < i + 1:
        if j == 0 or j == i:
            print(1, end="")
        else:
            print(2, end="")
        j = j + 1
    i = i + 1
    print()

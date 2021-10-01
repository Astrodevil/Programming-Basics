# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# *000*000*
# 0*00*00*0
# 00*0*0*00
# 000***000

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())
i = 1

while i <= n:
    j = 1
    m = 2 * n + 1
    while j <= m:
        if j == i or j == n + 1 or j == (m - i + 1):
            print("*", end="")
        else:
            print("0", end="")
        j += 1
    print()
    i += 1

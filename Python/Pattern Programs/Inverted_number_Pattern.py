# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# 4444
# 333
# 22
# 1

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines

n = int(input())

i = 1
while i <= n:
    j = 1
    m = n - i + 1
    while j <= m:
        print(m, end="")
        j += 1
    print()
    i += 1

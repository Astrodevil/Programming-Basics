# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# 1234
# 123
# 12
# 1

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())
i = 1
while i <= n:
    j = 1
    while j <= (n - i + 1):
        print(j, end="")
        j += 1
    i += 1
    print()

# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# 1      1
# 12    21
# 123  321
# 12344321

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines

n = int(input())

i = 1
while i <= n:
    j = 1
    while j <= i:
        print(j, end="")
        j += 1
    # mirror part
    spaces = 2 * (n - i)
    while spaces > 0:
        print(" ", end="")
        spaces -= 1
    p = i
    while p > 0:
        print(p, end="")
        p -= 1
    i += 1
    print()

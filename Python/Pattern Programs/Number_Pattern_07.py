# Print the following pattern for the given N number of rows.
# Pattern for N = 4

#    1
#   12
#  123
# 1234

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines

n = int(input())

i = 1
while i <= n:
    spaces = n - i
    while spaces > 0:
        print(" ", end="")
        spaces -= 1
    p = 1
    while p <= i:
        print(p, end="")
        p += 1
    i += 1
    print()

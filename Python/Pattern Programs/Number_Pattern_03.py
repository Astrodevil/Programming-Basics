# Print the following pattern for the given N number of rows.
# Pattern for N = 4

# 1
# 21
# 321
# 4321

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines

n = int(input())
i = 1


while i <= n:
    j = 1
    p = i
    while j <= i:
        print(p, end="")
        j += 1
        p -= 1
    i += 1
    print("")

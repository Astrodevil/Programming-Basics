# Print the following pattern for the given N number of rows.
# Pattern for N = 3

#  A
#  BB
#  CCC

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())
i = 1
while i <= n:
    j = 1
    while j <= i:
        chra = chr(ord("A") + i - 1)
        print(chra, end="")
        j += 1
    print()
    i += 1

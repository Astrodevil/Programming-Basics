# Print the following pattern for the given N number of rows.
# Pattern for N = 3

#  A
#  BC
#  CDE

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())

i = 1
start_chr = chr(ord("A") + i - 1)
while i <= n:
    j = 1
    while j <= i:
        x = ord(chr(ord("A") + i - 1))
        chra = chr(x + j - 1)
        print(chra, end="")
        x += 1
        j += 1
    print()
    i += 1

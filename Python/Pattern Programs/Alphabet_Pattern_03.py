# Print the following pattern for the given number of rows.
# Pattern for N = 5

# E
# DE
# CDE
# BCDE
# ABCDE

# Input format :
# N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())

i = 1
# start_chr = chr(ord("A") +n-i)
while i <= n:
    j = 1
    while j <= i:
        x = ord("A") + n - i + j - 1
        CHR = chr(x)
        print(CHR, end="")
        j += 1

    i += 1
    print()

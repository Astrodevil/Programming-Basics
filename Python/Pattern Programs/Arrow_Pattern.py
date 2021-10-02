# Print the following pattern for the given number of rows. Assume N is always odd.
# Pattern for N = 7

# Note : There is space after every star.

# *
#  * *
#   * * *
#    * * * *
#   * * *
#  * *
# *

# Input format :
# Integer N (Total no. of rows)
# Output format :
# Pattern in N lines


n = int(input())
i = 1
m = n // 2 + 1
# for increasing pattern
while i <= m:

    spaces = 1
    while spaces <= (i - 1):
        print(" ", end="")
        spaces += 1
    stars = 1
    while stars <= i:
        print("* ", end="")
        stars += 1
    print()
    i += 1
# for decreasing pattern
j = 1
while j <= m:
    spaces = m - j - 1
    while spaces > 0:
        print(" ", end="")
        spaces -= 1
    stars = m - j
    while stars > 0:
        print("* ", end="")
        stars -= 1
    print()
    j += 1

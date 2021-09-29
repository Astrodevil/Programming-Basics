# given a variable n (user input), the program
# prints lucas series upto n-numbers
# BACKGROUND: Lucas series is similar to fibonacci series, except
# the first two elements of the series can be anything

def lucas(n, elem):
    """A simple function to print lucas series of n-numbers"""

    # check if n is correct
    # we can only allow n >=3 and n as an integer number
    # since we always expect user to provide two elements
    # these two elements will be the starting number of the series
    try:
        n = int(n)
    except ValueError:
        raise TypeError("lucas series is only available for n-digits, where n is an integer, and n >= 3")
        
    if n < 3:
        raise ValueError("lucas series is only available for n-digits, where n is an integer, and n >= 1")

    # evaluate user-input elements
    try:
        elem = eval(elem)
    except SyntaxError:
        raise TypeError("unable to understand type of first two elements of the series")

    if type(elem) == tuple:
        # convert `elem` to list
        # so that we can append new values into list
        elem = list(elem)
        
    # when we are assured that the value of n is correct,
    # we can now calculate the lucas series upto n-elements
    # and finally return it as a string seperated by space
    for _ in range(n - 2):
        elem.append(sum(elem[-2:]))
            
    return " ".join(map(str, elem))


if __name__ == "__main__":
    n = input("Enter the Number of Elements of Lucas Series (n >= 3, and type(n) = int): ")
    elememnts = input("Enter the First Two Elements of Lucas Series (example input `[1, 2]`, `(1, 2)`, `1, 2`): ")
    print(lucas(n, elememnts))

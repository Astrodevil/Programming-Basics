# given a variable n (user input), the program
# prints fibinacci series upto n-numbers

def fibonacci(n):
    """A simple function to print fibonacci sequence of n-numbers"""

    # check if n is correct
    # we can only allow n >=1 and n as an integer number
    try:
        n = int(n)
    except ValueError:
        raise TypeError("fibonacci series is only available for n-digits, where n is an integer, and n >= 1")
        
    if n < 1:
        raise ValueError("fibonacci series is only available for n-digits, where n is an integer, and n >= 1")
        
    # when we are assured that the value of n is correct,
    # we can find the fibonacci sequence
    # and finally return it as a string seperated by space
    if n == 1:
        series = [0]
    elif n == 2:
        series = [0, 1]
    else:
        series = [0, 1]
        for _ in range(n - 2):
            series.append(sum(series[-2:]))
            
    return " ".join(map(str, series))


if __name__ == "__main__":
    n = input("Enter the Number of Elements of Fibonacci Series (n >= 1, and type(n) = int): ")
    print(fibonacci(n))

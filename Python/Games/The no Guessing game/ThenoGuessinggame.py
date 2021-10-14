#The Number Guessing Game.


inp1= input("Welcome to 'The Guessing Number Game!!!'\n"
            "Press Enter to move forward\n")

print("Do you want to start the game?\n"
      "Press 1 to start else 2 to quit the game")
inp2= int(input())

if inp2==2:
   print("You quit the game")

if inp2==1:
    print("Let's start the game")

    n = 18
    i = 0
    while (i < 9):
        i = i + 1
        print("Enter a number")
        x = int(input())
        if x == n:
            print("Congrats!! your number has matched")
            print("number guesses you took", i)
            break
        elif x < 18:
            print("Try again with a larger number")
            print("Chances left", 9 - i)
            continue
        elif x > 18:
            print("Try again with a smaller number")
            print("chances left", 9 - i)
        elif i > 9:
            print("OOPS!! U have used all ur chances")
            break

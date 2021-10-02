import time
import random
import math
from os import system



def restart():
    restart = input('''
Play Again? (Y/N): ''').upper()

    if restart == 'Y':
        
        time.sleep(2)
        system('cls')
        main()

    else:
        print('\n[EXITING]')
        time.sleep(2)
        exit()


def main():
    turns = 7
    usedchr = ""
    addchr = ""

    with open('hangmanwordlist.txt') as hangman:
        words = list(hangman.read().splitlines())
 
    secret_word = random.choice(words)

    while True:
        system('cls')
        print("LET'S PLAY HANGMAN!", end="\n")
        
        if turns == 0:
            print("[GAME OVER, YOU LOSE]")
            print(f"THE WORD IS '{secret_word}'")
            time.sleep(5)
            restart()

        else:
            blank = 0
            for char in secret_word:
                if char in addchr:
                    print(char, end=" ")

                else:
                    print("_",end=" ")
                    blank += 1

            else:
                if blank == 0:
                    print("\n[YOU WON]")
                    time.sleep(5)
                    restart()

            print(f"\n\nYou have {turns} Guesses.")
            if len(usedchr) > 0:
                print(f"[LETTERS TRIED: {usedchr}]")
            
            guess = input("\nGuess: ")

            if len(guess) > 1:
                print("[NO CHEATING, ENTER 1 CHR AT A TIME]")
                time.sleep(2)

            else:
                if guess in secret_word:
                    addchr += guess

                else:
                    print("[WRONG GUESS]")
                    time.sleep(0.5)
                    turns -= 1
                
                usedchr += guess + " "

                             

if __name__ == "__main__":
    main()
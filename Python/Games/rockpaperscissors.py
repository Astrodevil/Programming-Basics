# Code by - Siphyshu
# Last Modified: 07-06-2020

import random
import time
from os import system

# Standard Rock, Paper, Scissor Rules apply:
# 1. Stone > Scissor
# 2. Stone < Paper
# 3. Scissor > Paper
# 
# Notations:
# 0 - Nothing,
# R - Rock,
# P - Paper,
# S - Scissor

rock = """
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
"""

paper = """
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
"""

scissor = """
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
"""

def main():
    choices = {'R':rock, 'P':paper, 'S':scissor}
    # choices = {'R':'ROCK', 'P':'PAPER', 'S':'SCISSOR'}
    m_score, p_score = 0, 0
    while (m_score != 3) and (p_score != 3):
        system('cls')
        print("ROCK, PAPER & SCISSORS!")
        print(f"\n[Player({p_score}) vs. Machine({m_score})]")

        p_choice = ''
        print("\n[PLAYER'S TURN]")
        playerturn = input("(R)ock, (P)aper or (S)cissor: ").upper()
        if playerturn == "R":
            p_choice = 'R'

        elif playerturn == 'P':
            p_choice = 'P'

        elif playerturn == "S":
            p_choice = 'S'

        else:
            continue
        
        m_choice = random.choice(['R','P','S'])
        print("\n[MACHINE'S TURN]")
        loading()

        system('cls')
        print("ROCK, PAPER & SCISSORS!")
        print(f"\n[Player({p_score}) vs. Machine({m_score})]")
        print(f"\nYOU DREW: {choices[p_choice]}")
        print(f"MACHINE DREW: {choices[m_choice]}")



        outcome = win_checker(p_choice, m_choice)

        if outcome == False:
            print("\n[NO POINT AWARDED]")

        elif outcome == p_choice:
            p_score += 1
            print("\n[POINT TO PLAYER]")

        elif outcome == m_choice:
            m_score += 1
            print("\n[POINT TO MACHINE]")

        input("\n[Press ENTER]")

    system('cls')
    print("ROCK, PAPER & SCISSORS!")
    print(f"\n[SCORE: Player({p_score}) vs. Machine({m_score})]")
    
    if p_score == 3:
        print("\n[PLAYER WINS!]")
        print(r'''
$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$
$$$'`$$$$$$$$$$$$$'`$$$$$
$$$$  $$$$$$$$$$$  $$$$$$
$$$$. `$' \` \$`  $$$$$$$
$$$$$. !\  i  i .$$$$$$$$
$$$$$$   `--`--.$$$$$$$$$
$$$$$$L        `$$$$$^^$$
$$$$$$$.   .'   ""~   $$$
$$$$$$$$.  ;      .e$$$$$
$$$$$$$$$   `.$$$$$$$$$$$
$$$$$$$$    .$$$$$$$$$$$$
$$$$$$$     $$$$$$$$$$$$$''')

    elif m_score == 3:
        print("\n[MACHINE WINS!]")
        print(r'''
              ,---------------------------,
              |  /---------------------\  |
              | |                       | |
              | |     Machines          | |
              | |       Rules           | |
              | |         Humans        | |
              | |                       | |
              |  \_____________________/  |
              |___________________________|
            ,---\_____     []     _______/------,
          /         /______________\           /|
        /___________________________________ /  | ___
        |                                   |   |    )
        |  _ _ _                 [-------]  |   |   (
        |  o o o                 [-------]  |  /    _)_
        |__________________________________ |/     /  /
    /-------------------------------------/|      ( )/
  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~''')
        
    time.sleep(3)

    choose()




def win_checker(p1,p2):
    if p1 == p2:
        return False

    if p1 == 'R':
        if p2 == 'P':
            return p2

        else:
            return p1

    if p1 == 'P':
        if p2 == 'S':
            return p2

        else:
            return p1

    if p1 == 'S':
        if p2 == 'R':
            return p2

        else:
            return p1




def choose():
    while True:      
        ask = input("\n[Play Again? (Y/N)]: ").upper()

        if ask == 'Y':
            main()
            
        elif ask == 'N':
            print("\n[EXITING]")
            time.sleep(3)
            break

        else:
            pass




def loading():
    print("[", end="")

    for _ in range(0,25):
        time.sleep(0.05)
        print("█", end="", flush=True)


    print("]")




if __name__ == "__main__":
    main()        
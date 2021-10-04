import random
import time 
from os import system


def main():
    while True:
        system('cls')
        print("[WHEN IN DOUBT, LET THE PROGRAM DECIDE]")
        print(r'''
                         .-.
                         '-'
                        //
               _..---._/|
             .' ."     '-.
            /__/          \      *
           ====_____     __|     :
          /#   #""" |   /()\    :    ..*
          |#   #    |   \__/    : .'' 
          \#___#____|      /   :::.. .
           \______________|_...ä_: .. '*
  ()       // /\||||)))))))      '   . .
 .( \_     \\_\//   _-'.'/        |   * ..
( )  |^|^|^|ooo/  _#\.//"""_      |   . . .
(_)_.'v|v|v|     / \#  \_ / '_  _'    . .  
           | _ _/_/     /'./_-|"         . .
           /#_#__"""-._ /#  \__)       .  .   
           |__   ""-._ |##               . . .
           |  ""|-"""-_/##              . .    
           /""--\__.-|                       .
           \-_.-<__ /                   .   .
           /-_| /  \
           \-_| \_-<.                        .  .
           <_-/ <_.-\                    .
           <_-|  |_.-|                        .
      .----|   \__\  |                 .
     |     ."""   '.  |                       .
      .___|        |__|  (c) NamelessOne
          '.__..."""''')

        choose = input('''
(1) Roll a dice
(2) Pick a thing
(3) Flip a coin
ENTER: ''')

        if choose == '1':
            roll_dice()

        elif choose == '2':
            pick_thing()

        elif choose == '3':
            flip_coin()

        else:
            print("\n// error: unknown option!")
            time.sleep(2)
            system('cls')


def roll_dice():
    while True:
        system('cls')
        print("[DICE ROLLING SIMULATOR]")
        print(r'''
               (( _______
     _______     /\O    O\
    /O     /\   /  \      \
   /   O  /O \ / O  \O____O\ ))
((/_____O/    \\    /O     /
  \O    O\    / \  /   O  /
   \O    O\ O/   \/_____O/
    \O____O\/ ))          ))
  ((''')
        result = random.randint(1,6)
        print(f"\n[DICE SHOWS {result}]")
        choose = input("\n// Press enter to roll again\n// Q to go back to menu ")
        if choose == "":
            pass

        else:
            system('cls')
            break


def flip_coin():
    while True:
        system('cls')
        print("[COIN FLIP SIMULATOR]")
        result = random.choice(["H","T",])
        if result == 'H':
            print(r'''
        _.-'~~`~~'-._
     .'`  B   E   R  `'.
    / I               T \
  /`       .-'~"-.       `\
 ; L      / `-    \      Y ;
;        />  `.  -.|        ;
|       /_     '-.__)       |
|        |-  _.' \ |        |
;        `~~;     \\        ;
 ;          /      \\)     ;
  \        '.___.-'`"     /
   `\                   /`
     '._   1 9 9 7   _.'
        `'-..,,,..-'`''')

            print("\n[IT'S A HEADS]")

        else:
            print(r'''
        _.-'~~`~~'-._
     .'`  B   E   R  `'.
    / I               T \
  /`          _          `\
 ; L         /"|         Y ;
;          u | |u           ;
|           \| |/           |
|            |_|            |
;          _//<,-,          ;
 ;        (__)(_/)         ;
  \                       /
   `\                   /`
     '._   1 9 9 7   _.'
        `'-..,,,..-'`''')

            print("\n[IT'S A TAILS]")

        choose = input("\n// Press enter to roll again\n// Q to go back to menu ")
        if choose == "":
            pass

        else:
            system('cls')
            break


def pick_thing():
    while True:    
        system('cls')
        print("[RANDOM ITEM PICKER]")
        print(r'''
  .---------.
  |.-------.|
  ||>run#  ||
  ||       ||
  |"-------'|etf
.-^---------^-.
| ---~   AMiGA|
"-------------\'''')
        things = input("\n// List of items separated by '/': ").split("/")
        counter = input("// Number of items to pick: " )
        try:
            counter = int(counter)

        except:
            print("\n// error: should be an integer!")
            time.sleep(2)
            continue

        thing = random.choices(things,k=counter)
        toPrint = ", ".join(thing)[:-2]

        system('cls')
        print("[RANDOM ITEM PICKER]")
        print(r'''
  .---------.
  |.-------.|
  ||>run#  ||
  ||       ||
  |"-------'|etf
.-^---------^-.
| ---~   AMiGA|
"-------------\'''')

        print(f"\n[THE PROGRAM PICKS: {toPrint}]")

        choose = input("\n// Press enter to roll again\n// Q to go back to menu ")
        if choose == "":
            pass

        else:
            system('cls')
            break



if __name__ == "__main__":
    main()
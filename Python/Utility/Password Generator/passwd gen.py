import random
import time
from os import system


def main():
    while True:
        system('cls')
        print("[PASSWORD GENERATOR]")
        pwdtype = input('''
(1) xxx-xxx-xxx type
(2) random type
ENTER: ''')

        if pwdtype == '1':
            passwd = gen_typeone()
            print("\n[YOUR PASSWORD]")
            print(f"> {passwd}")
            input("\n[PRESS ENTER]")

        elif pwdtype == '2':
            passwd = gen_typetwo()
            print("\n[YOUR PASSWORD]")
            print(f"> {passwd}")
            input("\n[PRESS ENTER]")

        else:
            continue



def gen_typeone():
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    passwd = "-".join(("".join(random.sample(alphabet,k=3))) for _ in range(3))
    return passwd


def gen_typetwo():
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    numbers = '1234567890'
    symbols = '@$*-_#+'
    passwd = ""
    numsym = random.choice([1,2,3])
    numnum = random.choice([3,4,5])
    numalpha = 13 - numsym - numnum
    passwd = random.choices(alphabet, k=numalpha) + random.choices(numbers, k=numnum) + random.choices(symbols, k=numsym)
    
    for _ in range(3):
        random.shuffle(passwd)

    passwd  = "".join(passwd)
    return passwd

if __name__ == "__main__":
    main()


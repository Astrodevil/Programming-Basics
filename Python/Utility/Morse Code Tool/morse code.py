import os
import winsound
import time

timeunit = 300
frequency = 2500
dit = timeunit * 1
dash = timeunit * 3
inter_space = 1 * 0.300
space = 3 * 0.300
word_space = 7 * 0.300
morse_code_dict = {'A': '.-', 'B': '-...',
                   'C': '-.-.', 'D': '-..', 'E': '.',
                   'F': '..-.', 'G': '--.', 'H': '....',
                   'I': '..', 'J': '.---', 'K': '-.-',
                   'L': '.-..', 'M': '--', 'N': '-.',
                   'O': '---', 'P': '.--.', 'Q': '--.-',
                   'R': '.-.', 'S': '...', 'T': '-',
                   'U': '..-', 'V': '...-', 'W': '.--',
                   'X': '-..-', 'Y': '-.--', 'Z': '--..',
                   '1': '.----', '2': '..---', '3': '...--',
                   '4': '....-', '5': '.....', '6': '-....',
                   '7': '--...', '8': '---..', '9': '----.',
                   '0': '-----', ',': '--..--', '.': '.-.-.-',
                   '?': '..--..', '/': '-..-.', '-': '-....-',
                   '(': '-.--.', ')': '-.--.-', ';': '_._._.',
                   ':': '___...', "'": '.____.',
                   '"': '._.._.', '=': '_..._', '+': '._._.',
                   '*': '_.._', '@': '.__._.'}


def main():

    while True:
        os.system("cls")

        choose = input('''MORSE CODE DIT-DASH BEEP-BOOP

(1) ENG --> MORSE
(2) MORSE --> ENG
[Q to quit]
Enter: ''')

        if choose == '1':
            message = input('\nText: ')
            output = encrypt(message)
            # print(f"\nEnglish: {message}")
            print(f"Morse Code:\n{output}")
            print("\n[BEEPING MORSE CODE]")
            for word in output.split("  "):
                for ch in word:
                    if ch == ".":
                        winsound.Beep(frequency, dit)
                        time.sleep(inter_space)

                    elif ch == "-":
                        winsound.Beep(frequency, dash)
                        time.sleep(inter_space)

                    elif ch == " ":
                        time.sleep(space)

                    else:
                        for _ in range(8):
                            winsound.Beep(frequency, dit)

                else:
                    time.sleep(word_space)
            print("[OVER AND OUT]")

            input("\n[Press Enter to convert again]")

        elif choose == '2':
            print(
                "\nGUIDLINES: '.' for dot, '-' for dash, '  ' double-spaces between words\n")
            message = input('Morse: ')
            output = decrypt(message)
            # print(f"\nMorse Code: {message}")
            print(f"Decrypted Text:\n{output}")
            input("\n[Press Enter to convert again]")

        elif choose.upper() == 'Q':
            print("\nExiting . . .")
            time.sleep(1)
            os.system('cls')
            break

        else:
            os.system("cls")


def encrypt(message):
    cipher = ''
    for letter in message:
        if letter.upper() not in list(morse_code_dict.keys()) and letter != " ":
            cipher += letter + " "
            continue

        if (letter != ' '):
            cipher += morse_code_dict[letter.upper()] + ' '

        else:
            cipher += ' '

    return cipher


def decrypt(message):
    message += ' '
    decipher = ''
    morsym = ''

    for letter in message:

        if (letter != ' '):
            i = 0
            morsym += letter

        # if morsym not in list(morse_code_dict.keys()):
        #     decipher += " [ERROR] "
        else:
            i += 1

            if i == 2:
                decipher += ' '

            else:
                if morsym not in list(morse_code_dict.values()):
                    decipher += "[ERROR]"
                    morsym = ''
                    continue

                else:

                    decipher += list(morse_code_dict.keys()
                                     )[list(morse_code_dict.values()).index(morsym)]
                    morsym = ''

    return decipher


if __name__ == "__main__":
    main()

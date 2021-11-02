import string
alpha = string.ascii_lowercase

def alphabet_rangoli(size):
    list = []
    for row in range(size):
        hypen = "-".join(alpha[row:size])
        list.append(hypen[::-1] + hypen[1:])
    width = len(list[0])
    
    for row in range(size-1, 0, -1):
        print(list[row].center(width, '-'))
        
    for row in range(size):
        print(list[row].center(width, '-'))


alphabet_rangoli(int(input('Enter n = ')))

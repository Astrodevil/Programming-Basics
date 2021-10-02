"""
Question: You are given an integer,N. Your task is to print an alphabet rangoli of size N. 

Examples of Alphabet Rangoli

->size 3

----c----
--c-b-c--
c-b-a-b-c
--c-b-c--
----c----

->size 5

--------e--------
------e-d-e------
----e-d-c-d-e----
--e-d-c-b-c-d-e--
e-d-c-b-a-b-c-d-e
--e-d-c-b-c-d-e--
----e-d-c-d-e----
------e-d-e------
--------e--------

"""


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

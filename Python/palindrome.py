# First we take an input which is assigned to the variable "text"
# Then we use the python string slice method to reverse the string
# When both the strings are compared and an appropriate output is made


text=input("Enter the string to be checked: ")
palindrom_text= text[::-1]

if text==palindrom_text:
    print("Palindrome")
else:
    print("Not Palindrome")

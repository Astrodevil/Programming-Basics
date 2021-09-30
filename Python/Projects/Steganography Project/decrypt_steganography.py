# Import necessary libraries
from PIL import Image
import stepic
# Open the image from which the secret message is to be extracted:
# image = Image.open("C:\\Users\\Nitin Kumar\\OneDrive\\Documents\\encrypted.png")
img = input("Enter your picture with which you want to decrypt your message\n")
image = Image.open(img)
# Pass the above image into the decode() function.
# This function returns the secret message in the form of a string:
decoded_msg = stepic.decode(image)
print("Decryption Completed!\n")
# Display the message
print("Decoded Message:", decoded_msg)

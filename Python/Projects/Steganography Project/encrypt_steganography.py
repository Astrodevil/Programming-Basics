# Import necessary libraries
from PIL import Image
import stepic


# image = input("Enter your picture inside which you want to encrypt your message\n")
# new_img = input("Enter the new picture path where the output image should be placed:\n")

# Open the image within which the secret message is to be stored:
# img = Image.open("C:\\Users\\Nitin Kumar\\OneDrive\\Documents\\clg life-pics\\nitinPic.jpg")
image = input("Enter your picture inside which you want to encrypt your message:\n")
img = Image.open(image)
# Specify the secret message:
message = "Hey there! This is my encrypted message inside an image."
# Convert the message into UTF-8 format:
message = message.encode()
# Pass the image and message into the encode() function.
# This function returns a new image within which the message is hidden:
encoded_img = stepic.encode(img, message)
# Specify the name and extension for the new image generated:

# encoded_img.save("C:\\Users\\Nitin Kumar\\OneDrive\\Documents\\encrypted.png")
new_img = input("Enter the new picture path where the output image should be placed:\n")
encoded_img.save(new_img)
print("Encryption Completed!")

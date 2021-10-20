#Convert text file into audio

from gtts import gTTS
import os

print("Enter the full path of your text file to convert into audio: ")
location = input() #Taking the path of text file as input from user

basename = os.path.basename(location) #Getting filename (with extension i.e, filename.txt) to produce output as filename.mp3
basename = basename[:-4] # removing '.txt' extension from filename to produce output result as filename.mp3

yourFile = open(location, "r")
myText = yourFile.read().replace("\n", " ") #replaces new line (\n) of text with a space ( )

language = 'en'     #to convert text in English to English audio
#if your file is in other language and want the output audio in that language replace 'en' with your
#language example: 'ne' for Nepali, 'fr' for French and so on
output = gTTS(text=myText, lang=language, slow=False)

print("Converting text to audio...")
output.save(basename + ".mp3")

yourFile.close()
print("Finally! Your text is converted to audio.")

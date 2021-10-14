from tkinter import *
from PIL import ImageTk, Image
from datetime import datetime
from gtts import gTTS
from playsound import playsound
root = Tk()
root.title("TEXT TO AUDIO")
root.geometry("333x333")
root.maxsize(655,333)
root.config(background="PaleGreen1")

def audio():

    text = f"{text_value.get()}"
    sp = gTTS(text, tld='com', lang='en')
    date_string = datetime.now().strftime("%d%m%Y%H%M%S")
    filename = "voice"+date_string+".mp3"
    sp.save(filename)
    playsound(filename)

def click(*args):
    enter.delete(0, 'end')

l = Label(text="CONVERT TEXT TO AUDIO", relief=RIDGE, font="Arial 10 underline",
          bg="blue", fg="White").grid(column=1, sticky=N)

Label(text=" ", bg="PaleGreen1").grid()

Label(root, text="INPUT TEXT", font="Arial 10",  relief=RIDGE,
      bg="blue", fg="White").grid(row=2, column=0)

text_value = StringVar()

enter = Entry(root, textvariable=text_value, bg="azure")

enter.insert(0, 'Enter Text:- ')
enter.bind("<Button-1>", click)
enter.grid(row=2, column=1)

image = Image.open("click_me.png")
image = image.resize((100, 30))
image = ImageTk.PhotoImage(image)

clickMe_button = Button(text="Play", image=image, command=audio,
                        highlightcolor="Green").grid(row=3, column=1)

exit_button = Button(root, text="Exit",background="Green", command=root.destroy).grid(row=4, column=1)

root.mainloop()

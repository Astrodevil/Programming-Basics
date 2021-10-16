from tkinter import *
from tkinter import filedialog, messagebox

# imported all modules

root = Tk()
root.geometry("520x600")
root.title("Nitin's Notepad")


# ---------------------------------------------------
# define methods for button functionality

def save_file():
    open_file = filedialog.asksaveasfile(mode='w', defaultextension=".txt") # change defaultextension's value to '*.*'
    if open_file is None:
        return
    text = str(entry.get(1.0, END))
    open_file.write(text)
    open_file.close()


def clear():
    messagebox.showinfo("Cleared", "Cleared all contents !")
    entry.delete(1.0, END)


def open_file():
    file = filedialog.askopenfile(mode='r', filetype=[('text files', '*.txt')])
    if file is not None:
        content = file.read()
    entry.insert(INSERT, content)


# --------------------------------------------

# Buttons & Textbox placement

b1 = Button(root, text="Save File", command=save_file)
b1.place(x=10, y=10)

b2 = Button(root, text="Clear", command=clear)
b2.place(x=70, y=10)

b3 = Button(root, text="Open File", command=open_file)
b3.place(x=120, y=10)

entry = Text(root, height=60, width=70, wrap=WORD, bg="black", fg="yellow", selectbackground="blue",
             font="Courier 15", insertbackground="violet")
entry.place(x=10, y=50)

root.mainloop()

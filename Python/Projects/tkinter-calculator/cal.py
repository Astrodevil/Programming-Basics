from tkinter import *
from tkinter import messagebox

SCREEN = Tk()


# variable
hist = []
# method
def click(event):
    global cal_val
    text = event.widget.cget("text")
    if text == 'C':
        cal_val.set("")
        inp.update()
        
    elif text == '=':
        if cal_val.get() != "":
            if cal_val.get().isdigit():
                value = int(cal_val.get())
            else:
                value = eval(inp.get())
            cal_val.set(value)
            hist.append(value)
            print(hist)
            inp.update()
        else:
            pass
    
    elif text == "\u232b":
        val_len = len(cal_val.get())
        inp.delete(val_len - 1, 'end')
        
    else:
        cal_val.set(cal_val.get()+ text)
        

def histr():
    root = Tk()
    i =0
    l = Listbox ( root )
    for his in hist:
        l.insert(i, his)
        i+=1
    l.pack()
    root.mainloop()

# main screen
SCREEN.geometry("360x560")
a,b = 360,560
SCREEN.minsize(a,b)
SCREEN.maxsize(a,b)

# title and icon
SCREEN.title("Toothless Calculator")

# Heading
heading = Label(text="Toothless Calculator", font="arial 14 bold")
heading.pack(fill="x")

# INPUT
cal_val = StringVar()
cal_val.set("")
inp = Entry(SCREEN, textvar= cal_val, justify='right', font="lucida 30 bold", relief=RIDGE)
inp.pack(fill="x", ipady=5)

# frames
f_maintop = Frame(SCREEN, bg='lightblue')
b= Button(f_maintop, text="C", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f_maintop, text="\u232b", padx= 8,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f_maintop, text="/", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f_maintop, text="*", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
f_maintop.pack(pady=5)


# top
f1_top = Frame(SCREEN, bg='lightblue')
b= Button(f1_top, text="7", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f1_top, text="8", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f1_top, text="9", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f1_top, text="-", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
f1_top.pack(pady=5)

# mid
f2_mid = Frame(SCREEN, bg='lightblue')
b= Button(f2_mid, text="4", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f2_mid, text="5", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f2_mid, text="6", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f2_mid, text="+", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
f2_mid.pack(pady=5)

# bottom
f3_bottom = Frame(SCREEN, bg='lightblue')
b= Button(f3_bottom, text="1", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f3_bottom, text="2", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f3_bottom, text="3", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b_eq = Button(f3_bottom, text="=", padx= 10,  font="lucida 25 bold")
b_eq.pack(side=LEFT, padx=10, pady= 10)
b_eq.bind("<Button-1>", click)
f3_bottom.pack(pady=5)

# main_end
f4_end = Frame(SCREEN, bg='lightblue')
b= Button(f4_end, text="0", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f4_end, text="00", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b = Button(f4_end, text=".", padx= 10,  font="lucida 25 bold")
b.pack(side=LEFT, padx=10, pady= 10)
b.bind("<Button-1>", click)
b1 = Button(f4_end, text="Hist", command=histr , padx= 10,  font="lucida 25 bold").pack(side=LEFT, padx=10, pady= 10)
f4_end.pack(pady=5)


SCREEN.mainloop()

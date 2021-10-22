from tkinter import *

root = Tk()
root.geometry("800x550")
root.resizable(False, False)
root.title("Toothless todo")

heading = Label(root, text="Todo app", font=("Goudy old style", 24, 'bold'), fg="#007AFF").pack()

def add_task():
    global textVar
    if textVar.get() != "":
        todo_tasks.insert("end", textVar.get())
        textVar.set("")
        root.update()
        
    else:
        print("please enter")

def del_task():
    selected = todo_tasks.curselection()
    if selected != ():
        todo_tasks.delete(selected)
        root.update()
    else:
        print("No")

        
 
textVar = StringVar()   
    
scroll = Scrollbar(root, orient="vertical")
todo_tasks = Listbox(root, font="cursive 15", width="700", height="17", yscrollcommand=scroll.set)
scroll.config(command=todo_tasks.yview)

scroll.pack(side="right", fill="y")

todo_tasks.pack(padx = 10)

task_input = Entry(root, font="arial 16", textvariable=textVar)
task_input.pack(fill=X, padx=15)
add_btn = Button(root, text="Add task", command=add_task, font=("cursive", 15), fg="white", bg="green").place(x=80, y=500, width="200", height="40")
del_btn = Button(root, text="Delete task", command=del_task, font=("cursive", 15), fg="white", bg="red").place(x=500, y=500, width="200", height="40")



root.mainloop()

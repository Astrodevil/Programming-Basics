from tkinter import *
from tkinter import messagebox
from PIL import ImageTk, Image



def submit():
    print("submitted")
    
def forget():
    print("forget")
    
is_on = True
    
class Login:
    def __init__(self, root):
        self.root = root
        self.root.geometry("1199x600+200+100")
        self.root.title("Login")
        self.root.resizable(False, False)
        
        # Image
        self.bg = Image.open("bg_img.jpg")
        
        resized = self.bg.resize((1199,600), Image.ANTIALIAS)
        self.new_bg_img= ImageTk.PhotoImage(resized)
        self.bg_img = Label(self.root, image=self.new_bg_img).pack()
        
        
        
        # Frame
        f_login = Frame(self.root, bg='white', relief=RAISED)
        f_login.place(x=328, y=99, height=410, width=545)
        
        label_Head = Label(f_login, text="Login Here!", font="Impact 30 bold", fg="#d77377", bg="white").place(x=90,y=30)
        label_desc = Label(f_login, text="Hey welcome back!", font=("goudy old style", 15 , "bold"), fg="grey", bg="white").place(x=110,y=80)
        
        
        label_User = Label(f_login, text="Username:", font="Impact 20 bold", fg="#d77377", bg="white").place(x=40,y=150)
        self.txt_user = Entry(f_login, font="cosmic 15", bg="#dcdcdc")
        self.txt_user.place(x=210,y=160)
        label_pass = Label(f_login, text="Password:", font=("Impact", 20 , "bold"), fg="#d77377", bg="white").place(x=40,y=200)
        self.txt_pass = Entry(f_login, font="cosmic 15", bg="#dcdcdc", show='*')
        self.txt_pass.place(x=210,y=210, width=225, height=30)
        self.btn_eye = Button(self.txt_pass, text="s", command=self.show,  cursor="hand2", bd=0).pack(side=RIGHT, ipadx=5)
        
        forget_btn = Button(f_login, text="Forget password.", command=forget,cursor="hand2", font="sansherif 15", fg="#d77377", bg="white",bd=0, relief=SUNKEN).place(x=130, y=290)
        submit_btn = Button(f_login, text="Submit", command=self.login_msg, cursor="hand2", font="cosmic 15", fg="white" , bg="#d77377", relief=RAISED).place(x=360, y=290, width=120, height=40)
        
    
    def login_msg(self):
        if self.txt_user.get() == "" or self.txt_pass.get() == "":
             messagebox.showerror("error", "All fields are required.", parent=self.root)
        elif self.txt_user.get()!="user123" or self.txt_pass.get()!="password@123":
             messagebox.showerror("error", "username/password invalid!", parent=self.root)
        else:
            user = self.txt_user.get()
            self.root.destroy()
            root=Tk()
            root.geometry("1199x600+200+100")
            Lable_home = Label(root, text=f"Welcome, {user}", font="Impact 20 bold", fg="#d37737").pack()
            
            logOut_btn = Button(root, text="Logout", font="sans-sherif 10", fg="white", bg="#d37737").place(x=1000, y=10, width=100, height=40)
            root.mainloop()
            
        # show password 
    def show(self):
        global is_on
        if is_on:
            self.txt_pass.config(show="")
            is_on = False
        else:
            self.txt_pass.config(show="*")
            is_on = True
            
root = Tk()
obj = Login(root)
root.mainloop()

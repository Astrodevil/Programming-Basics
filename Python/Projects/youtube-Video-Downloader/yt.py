from tkinter import *
from tkinter import ttk
from tkinter import filedialog
from pytube import YouTube # YouTube('https://youtu.be/2lAe1cqCOXo').streams.first().download()
import time

class Yt:
    def __init__(self, SCREEN):
        self. SCREEN = SCREEN
        
        # Gui title and geometry
        self.SCREEN.geometry("800x500+350+160")
        self.SCREEN.title("YTdownloader")
        self.SCREEN.resizable(False, False)
        
        # Main frame
        self.frame_main = Frame(self.SCREEN, bg="#000000")
        self.frame_main.place(x=0,y=0, width=800, height=500)
        
        # heading lable
        label_head = Label(self.frame_main, text="2thy YT Downloader", font=("Goudy old style", 20, "bold"), fg="white", bg="#000000").place(x=300, y=20)
        
        # Entry_link
        label_paste = Label(self.frame_main, text="Paste the video URL here", font=("arial", 15, "bold"), fg="white", bg="#000000").place(x=40, y= 100)
        

        self.paste_link = Entry(self.frame_main, font="arial 11")
        self.paste_link.place(x=300, y= 100, height=30, width=470)
        
        # Quality
        label_paste = Label(self.frame_main, text="Choose format.", font=("arial", 15), fg="white", bg="#000000").place(x=40, y= 150)
        self.options = ["High Quality", "Low Quality", "only Audio"]
        self.type_select = ttk.Combobox(self.frame_main, values=self.options, width=23)
        self.type_select.current(0)
        self.type_select.place(x=200, y= 150, height=30, width=120)
        
        # Select path
        self.select_path = Button(self.frame_main, text="Select folder", command=self.loc, fg="#000000", bg="#fff").place(x=400, y=145, height=40, width=240)
        
        
        # progressbar and download
        self.bar = ttk.Progressbar(self.frame_main, orient=HORIZONTAL, length=500, mode = 'determinate')
        self.bar.place(x=40, y=220)
        dwn_btn = Button(self.frame_main, text="Download", command=self.download, font="cosmic 10 bold", fg="white", bg="red").place(x=620, y=210, height=40, width=140)
        
        # errors
        self.label_error = Label(self.frame_main, text="", font=("Goudy old style", 15, "bold"), fg="red", bg="#000000")
        self.label_error.place(x=280, y= 270)
        
        # Output
        self.label_output = Label(self.frame_main, text="-----------------------  Output  -----------------", 
                                  font=("Goudy old style", 15, "bold"), fg="#fff", bg="#000000")
        self.label_output.place(x=300, y= 320)
        
        # File name
        self.file_name = Label(self.frame_main, text="Name:", font=("Goudy old style", 15, "bold"), fg="red", bg="#000000").place(x=40, y= 370)
        
        self.file_name_n = Label(self.frame_main, text="", font=("arial", 12, "bold"), fg="white", bg="#000000")
        self.file_name_n.place(x=260, y= 375)
        
        
        # file size
        self.file_size = Label(self.frame_main, text="Size:", font=("Goudy old style", 15, "bold"), fg="red", bg="#000000").place(x=40, y=410)
        
        self.file_size_s = Label(self.frame_main, text="", font=("arial", 12, "bold"), fg="white", bg="#000000")
        self.file_size_s.place(x=260, y=415)
        
        
        
        # file location
        self.file_location = Label(self.frame_main, text="File directory:", font=("Goudy old style", 15, "bold"), fg="red", bg="#000000").place(x=40, y=450)
        
        self.file_location_l = Label(self.frame_main, text="", font=("arial", 10), fg="white", bg="#000000")
        self.file_location_l.place(x=260, y=455)
        
        
        
    def loc(self):
        self.directory = filedialog.askdirectory()
          
    def download(self):
        yt_url = str(self.paste_link.get())
        yt_link = YouTube(yt_url)
        selected = self.type_select.get()
        print(selected)
        if self.paste_link.get() != "":
            self.label_error.config(text="")
            self.SCREEN.update()
            
            if selected == self.options[0]:
                dn = yt_link.streams.filter(progressive=True).first()
            elif selected == self.options[1]:
                dn = yt_link.streams.filter(progressive=True).last()
            elif selected == self.options[2]:
                dn = yt_link.streams.filter(only_audio=True).first()
                
            
            size = dn.filesize/1024000
            size = round(size,1)
            a=10
            while True:
                if a!=110:
                    time.sleep(1)
                    self.bar['value'] = a
                    dn.download(self.directory)
                    a += 10
                    self.frame_main.update_idletasks()
                else:
                    self.label_error.config(text="Download Complete")
                    break
                        
            self.file_name_n.config(text=yt_link.title)
            self.file_size_s.config(text=f"{size}MB")
            self.file_location_l.config(text=f"{self.directory}/{yt_link.title}")
        else:
            self.label_error.config(text="PLease enter the link.")
        


SCREEN = Tk()
obj = Yt(SCREEN)
SCREEN.mainloop()

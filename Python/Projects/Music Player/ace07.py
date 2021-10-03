#importing necessary modules
import pygame
import tkinter as tkr
from tkinter.filedialog import askdirectory
import os
#creating application window
musicplayer = tkr.Tk()
#setting the title name
musicplayer.title("Music Player")
#setting the dimensions
musicplayer.geometry("450x350")

directory = askdirectory()

os.chdir(directory)

songlist =os.listdir()

playlist =tkr.Listbox(musicplayer, font="sans-serif 14 bold",bg="green",selectmode=tkr.SINGLE)

for item in songlist:
    pos=0
    playlist.insert(pos,item)
    pos=pos+1

pygame.init()
pygame.mixer.init()

def play():
    pygame.mixer.music.load(playlist.get(tkr.ACTIVE))
    var.set(playlist.get(tkr.ACTIVE))
    pygame.mixer.music.play()

def ExitMusicPlayer():
    pygame.mixer.music.stop()

def pause():
    pygame.mixer.music.pause()

def resume():
    pygame.mixer.music.unpause()
def next_song():
    next_one= song_box.curselection()

Button_play =tkr.Button(musicplayer,height=3,width=5,text="Play",font="sans-serif 10 bold",command=play,bg="orange",fg="yellow")

Button_pause =tkr.Button(musicplayer,height=3,width=5,text="Pause",font="sans-serif 10 bold",command=pause,bg="black",fg="white")
Button_resume =tkr.Button(musicplayer,height=3,width=5,text="Resume",font="sans-serif 10 bold",command=resume,bg="black",fg="white")
Button_stop =tkr.Button(musicplayer,height=3,width=5,text="Stop",font="sans-serif 10 bold",command=ExitMusicPlayer,bg="black",fg="white")
Button_next =tkr.Button(musicplayer,height=3,width=5,text="Next",font="sans-serif 10 bold",command=next,bg="black",fg="white")
Button_play.pack(fill="x")

Button_pause.pack(fill="x")
Button_resume.pack(fill="x")
Button_stop.pack(fill="x")
Button_next.pack(fill="x")
playlist.pack(fill="both",expand="yes")

var=tkr.StringVar()
songtitle=tkr.Label(musicplayer,font="sans-serif 20 italic",textvariable=var)
songtitle.pack()
musicplayer.mainloop()

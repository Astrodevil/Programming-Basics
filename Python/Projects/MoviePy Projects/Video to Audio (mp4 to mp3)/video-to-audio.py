# install the module 'moviepy' first if you haven't
# pip install moviepy

from moviepy.editor import *

video_mp4= input("Enter video file's name along with extension- ")

audio_mp3= input("Enter file name for the converted audio (without extension)- ")

clip= VideoFileClip(video_mp4)
audio= clip.audio
audio.write_audiofile(audio_mp3+".mp3")

clip.close()
audio.close()
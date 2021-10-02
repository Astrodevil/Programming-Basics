# install the module 'moviepy' first if you haven't
# pip install moviepy

from moviepy.editor import VideoFileClip

video= input("Enter video file's name along with extension- ")

print("Choose FPS rate from anywhere between 5 to 20.")
fpsrate= int(input("Enter FPS- "))
while fpsrate<5 or fpsrate>20:
	fpsrate= int(input("Enter FPS rate accordingly- "))

savedgif= input("Enter file name for the converted GIF image (without extension)- ")
savedgif= savedgif+".gif"

clip= VideoFileClip(video)
clip.write_gif(savedgif, fps= fpsrate)
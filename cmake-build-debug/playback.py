# Will need to configure a python interpreter
# pip3 install time
# pip3 install pygame
import time
from pygame import mixer
import sys
from playsound import playsound

def main(mp3):
    mixer.init()
    playsound(mp3)
    while mixer.music.get_busy():
        time.sleep(1)
mp3 = sys.argv[1]
main(mp3)
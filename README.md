# Instrument Machine
December 13th, 2021

This project is a beat pad that plays several variations of two songs of two genres, House and Hip Hop. Their specs 
to be used in the graphical portion of the project are a product of their superclass, Genre. When the user starts 
the program, they are able to choose to enter three windows, one with House music buttons, one with Hip Hop, and 
a random sound button (just for fun).

To run this program, you should make sure you have all the necessary libraries and modules installed for both
Python and C++. There's a chance you don't have the following installed:

#C++:
<time.h>
<string>
<filesystem>

#Python:
time, pygame, mixer, sys, playsound



If this is the case, simply enter "pip3 install ___" and the subsequent module/library in your terminal.

Now, once the program is launched, mess around! The Genre implementations take keyboard input for the sound playback.
Notice the difference based on the graphical structure of them. One plays isolated instruments, one plays portions
of a track, and one plays the entire track, start to finish.

For the random button generator, just press the space bar and see if you can hear all the different possibilities.

It's possible the mp3 files will not want to load - they are all located in the cmake-build-debug folder - try moving them to the 
general project folder and back if that is the case - I resolved this issue by reformatting the files, but there's a chance
it acts up again, and in that case, this solution worked for me.

Have fun with it!
  


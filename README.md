# Instrument Machine
December 13th, 2021

This project is a beat pad that plays several variations of two songs of two genres, House and Hip Hop. Their specs 
to be used in the graphical portion of the project are a product of their superclass, Genre. When the user starts 
the program, they are able to choose to enter three windows, one with House music buttons, one with Hip Hop, and 
a random sound button (just for fun). The music was all produced by myself!

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

During playback, the python file freezes the event-based programming nature of the beat pad. This is expected. Lisa
gave me the go ahead to allow that to remain, as it is efficient and really the only option for playback regardless of OS.

It's possible the mp3 files will not want to load - they are all located in the cmake-build-debug folder - try moving them to the 
general project folder and back if that is the case - I resolved this issue by reformatting the files, but there's a chance
it acts up again, and in that case, this solution worked for me.

Please have fun with it! I really enjoyed this project and I hope you can appreciate the effort that went into efficient
playback of these tracks, and the time it took to produce them as well to be able to create a unique project. 
Thank you!

Citations: This project was built with code initially authored by Lisa Dion, Computer Science Lecturer at the University of Vermont. The files used in this project that are her own or were influenced by her code include the following:
  cmake_install.cmake
  CMakeLists.txt
  Button.h, Button.cpp (framework)
  Quad.cpp, Quad.h (framework)
  Graphics.cpp, Graphics.h (framework)
  


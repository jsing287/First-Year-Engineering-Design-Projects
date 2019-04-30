# First-Year-Engineering-Design-Projects
The two files within this repository were used for my 1050 Engineering Design Final Showcase project at Western 
University. These two programs were used to teach second year software engineering students the applications of machine
learning and Artificial Intelligence. The first program is the Processing.pde program which is used for facial detection.
I created this program with the use of the OpenCV open source computer vision library. This library provides a facial
detection program which scans pictures and then draws green rectangles around the detected faces. I then modified
this code to scan live video feed and draw green rectangles around the detected faces. To add to this I created an Arduino
program which is the .ino program within this repository. The program lights up LEDs based on the number of faces detected.
The processing program sends the number of faces detected to the Arduino program via the computer's serial ports. 
The Arduino program then used this number to control the input/output pins on the microcontroller to light up
LEDs on a breadboard. This visual aid resulted in positive feedback from both the judges and professors at the showcase.

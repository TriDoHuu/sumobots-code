# 🤖 sumobots-code
# Getting Started
Open up your arduino IDE and configure the right setting for your port and arduino nano. If you're not sure how to code, PLEASE watch our arduino basics and motor control workshop videos [here](https://www.youtube.com/watch?v=Qaol1ywlcjQ&ab_channel=UNSWMechatronicsSociety).

# Getting Started with the Arduino IDE
## Setup
Covered in Workshop 4, download and set up the Arduino IDE
1. Download the Arduino IDE [here](https://www.arduino.cc/en/software) or at https://www.arduino.cc/en/software
2. Create a new sketch
3. Copy & paste the code in MotorControlDemo.ino to test whether you have connected your sumobot correctly
4. To upload code to your sumobot, connect it to your computer, and select the correct port and board type in the top left (Port should look something like "usbserial", "COM5" or similar. A trick you can use to identify the port is by disconnecting and reconnecting the port and seeing which port disappears from the list)
   
### Upload Errors
If you have no errors, you are in luck!

It's always a mission uploading code using the IDE, here's a fix to a common error that occurs:

Run the old bootlegger. Go to Tools > Processor > Atmega328P(Old bootlegger):

Now try uploading again, it should work!

If the same or similar error still persists, ensure the right board and port is selected, press the reset button on the arduino or restart your IDE.

## 🏍️ Testing Your Motors
MotorControlDemo.ino is a small program that will allow you to test whether you have soldered your motor pins correctly, and test out motor movement. You may also like to take some inspiration from the functions in your own sumobot code!

## 📁 Code files:
- standardStarterCode.ino - A basic scaffold of sumobot code
- standardEasierStarterCode.ino - The basic sumobot scaffold with examples of functions, system states, etc... for those who are less familiar with coding
- advancedStarterCode.ino - Starting scaffold for the advanced stream, standard stream may find this code too complex

# Programming tips:
## For those unfamiliar with code
If you haven't completed COMP1511 yet, and you want to try to code your sumobot, we have prepared some slides on the basics of coding (quiz included), available [here](https://www.canva.com/design/DAGI8cjTvJ0/wV9paa2z3HaPYgHhJyGpxg/edit)

There are also mentors that are happy to help you out, and if we're not available, surely your teammates would lend a helping hand, right?

## General Sumobot Coding Advice
- One approach discussed briefly at the end of workshop 4 and/or in week 5's build session was to use system states, implemented using a switch/case statement, as well as a variable to keep track of which state your sumobot is currently in.
  - Coding system states is also covered in the [slides](https://www.canva.com/design/DAGI8cjTvJ0/wV9paa2z3HaPYgHhJyGpxg/edit)
- Try not to make functions too long, as it can make code hard to read. If you find that a certain piece of code is too long, see if you can direct the functionality to another function.
- Don't overthink it; Oftentimes the simplest code is the best solution
- Stick with a consistent coding style - Makes code easier to read

# Help
Help is available from:
- the Discord
- Workshop slides (also on the discord)
- Mentors at build sessions
- Team Mentors (for standard stream)

# Arduino-Voice-Controlled-Robot
Hey there, here in this article, I’m going to guide you to make an Arduino Voice Controlled Robot. This is very easy to make (for beginners) and very few components will be needed.


How Arduino Voice Controlled Robot Works?
As we have already mentioned that this is an Arduino-based project, so Arduino is working here as the brain of the robot. Everything we command to move the robot will be processed by the Arduino Microcontroller. We have to write a suitable code that will help the Arduino to process and follow our instructions.

Next we need a motor driver to control the speed of the motors according to the instruction given by the Arduino Microcontroller. So, here we are going to use an L293D motor driver shield which is really very easy to connect with the motors as we as the Arduino Board.
Next, we want to send our voice command wirelessly. So here we have decided to use HC-05 Bluetooth Module which is compatible with Arduino & our Android Phone.
In the next step, we have to install an Android App and have to connect our phone with the boat via Bluetooth. Now we will send the voice command using the android app to move the boat as we wish.
Here we have added Five voice commands for Five different instructions. They are
Move Forward – The Boat will move in the forward direction for 2 second
Move Backward – The boat will move in any backward direction for 2 second
Turn Right – The boat will make a 90 ̊rotation on its right side
Turn Left – The boat will make a 90 ̊ rotation on its left side

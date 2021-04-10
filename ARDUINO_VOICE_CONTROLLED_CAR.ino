// Arduino Voice Controlled Car
// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //
//Servo Library https://github.com/arduino-libraries/Servo.git //

#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
#include <Servo.h>   //Servo library. This is standard library. (Sketch -> Include Library -> Servo)
String voice;

AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor3 (3, MOTOR34_1KHZ); //create motor #3 ysing M3 output on Motor Driver Shield,set to 1kHz PWM frequency
AF_DCMotor motor4 (4, MOTOR34_1KHZ); //create motor #4 ysing M4 output on Motor Driver Shield,set to 1kHz PWM frequency

Servo myServo; //define servo name


void setup()
{
  Serial.begin(9600); //start serial communication
  myServo.attach(10); //define our servo pin (the motor shield servo1 input = digital pin 10)
  myServo.write(90);  //servo position is 90 degrees
  
}

void loop() 
{
  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
    if(voice == "*move forward"){
      forward_car();
      }
    else if(voice =="*move backward"){
      back_car();
      }
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
      left_car();
    }
    else if(voice == "*stop") {
      stop_car();
    }
    
  voice=""; //Reset the variable after initiating
  }
}

void forward_car()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
  delay(1500);
  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE); //Stop the motor
  motor3.run(RELEASE); //Stop the motor
  motor4.run(RELEASE); //Stop the motor
}
  
void back_car()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise]
   delay(1500);
  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE); //Stop the motor
  motor3.run(RELEASE); //Stop the motor
  motor4.run(RELEASE); //Stop the motor
}
  
void right_car()
{
  myServo.write(0);
  delay(500);
  myServo.write(90);
  delay(500);
   motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
  delay(700);
  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE); //Stop the motor
  motor3.run(RELEASE); //Stop the motor
  motor4.run(RELEASE); //Stop the motor
}
void left_car()
{
  myServo.write(180);
  delay(500);
  myServo.write(90);
  delay(500);
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
  delay(700);
  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE); //Stop the motor
  motor3.run(RELEASE); //Stop the motor
  motor4.run(RELEASE); //Stop the motor
}

void stop_car ()
{
  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE); //Stop the motor
  motor3.run(RELEASE); //Stop the motor
  motor4.run(RELEASE); //Stop the motor
}

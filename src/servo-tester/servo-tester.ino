/*

Script for checking servos.
Write Axxx on serial to set yaw servo position.
Write Bxxx on serial to set pitch servo position.

xxx - angle in degrees.

*/

#include <Servo.h>

const int yawServoPin = 2;
const int pitchServoPin = 4;

const int yawServoMin = 0;
const int yawServoMax = 180;

const int pitchServoMin = 40;
const int pitchServoMax = 110;

Servo yawServo;
Servo pitchServo;

String command;
char servoCode;
int value;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  yawServo.attach(yawServoPin);
  pitchServo.attach(pitchServoPin);

  yawServo.write(90);
  pitchServo.write(90);
}

// the loop function runs over and over again forever
void loop()
{
  while (Serial.available() == 0) {}
  command = Serial.readString();
  command.trim();

  servoCode = command.charAt(0);
  value = command.substring(1, 5).toInt();

  Serial.println(command);
  Serial.println(servoCode);
  Serial.println(value);

  if(servoCode == 'A' && value >= yawServoMin && value <= yawServoMax)
  {
    yawServo.write(value);
  }

  if(servoCode == 'B' && value >= pitchServoMin && value <= pitchServoMax)
  {
    pitchServo.write(value);
  }
}

#include <Servo.h>

#define YAW_SERVO_PIN 2
#define PITCH_SERVO_PIN 4

#define MAX_SERVO_MOVE_ANGLE 10

const int yawServoMin = 0;
const int yawServoMax = 180;

const int pitchServoMin = 40;
const int pitchServoMax = 110;

Servo yawServo;
Servo pitchServo;

int currentYawServoPosition = 90;
int currentPitchServoPosition = 90;


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  yawServo.attach(YAW_SERVO_PIN);
  pitchServo.attach(PITCH_SERVO_PIN);

  yawServo.write(currentYawServoPosition);
  pitchServo.write(currentPitchServoPosition);
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);

  currentYawServoPosition = getRandomServoPosition(currentYawServoPosition, yawServoMin, yawServoMax);
  currentPitchServoPosition = getRandomServoPosition(currentPitchServoPosition, pitchServoMin, pitchServoMax);

  yawServo.write(currentYawServoPosition);
  pitchServo.write(currentPitchServoPosition);

  delay(100);

  digitalWrite(LED_BUILTIN, LOW); 

  delay(900);
}

int getRandomServoPosition(int currentPosition, int minPosition, int maxPosition)
{
  int randomMin = currentPosition - MAX_SERVO_MOVE_ANGLE;
  int randomMax = currentPosition + MAX_SERVO_MOVE_ANGLE;

  int minPositionDifference = randomMin - minPosition;

  if(minPositionDifference < 0)
  {
    randomMin = randomMin - minPositionDifference;
    randomMax = randomMax - minPositionDifference;
  }

  int maxPositionDifference = maxPosition - randomMax;

  if(maxPositionDifference < 0)
  {
    randomMin = randomMin + maxPositionDifference;
    randomMax = randomMax + maxPositionDifference;
  }

  return random(randomMin, randomMax);
}

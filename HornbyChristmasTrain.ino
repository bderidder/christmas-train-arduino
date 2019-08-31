#include "MotorChannel.h"

const int PIN_CHANNEL_A_DIRECTION = 12;
const int PIN_CHANNEL_A_BRAKE = 9;
const int PIN_CHANNEL_A_SPEED = 3;

MotorChannel* motorChannelA;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initializing Channel A of Motor Shield");

  motorChannelA = new MotorChannel(ChannelAPinConfiguration, 12, 10);
}

void loop()
{
  forwardAndReverseTest();

  //incrementTest();
}

void forwardAndReverseTest()
{
  Serial.println("Spinning motor on channel A at full speed in forward direction");

  motorChannelA->moveForward();
  motorChannelA->disengageBrake();
  motorChannelA->setSpeed(100);

  delay(3000);

  Serial.println("Applying brake to channel A");
  
  motorChannelA->engageBrake();
  
  delay(3000);

  Serial.println("Spinning motor on channel A at half speed in reverse direction");

  motorChannelA->moveReverse();
  motorChannelA->disengageBrake();
  motorChannelA->setSpeed(50);
    
  delay(3000);

  Serial.println("Spinning motor on channel A to full speed over a period of 5 seconds");

  motorChannelA->moveForward();
  motorChannelA->disengageBrake();
  motorChannelA->setSpeed(0);

  motorChannelA->accelerateTo(100, 5000);
    
  delay(3000);

  Serial.println("Applying brake to channel A");
  
  motorChannelA->engageBrake();
  
  delay(2000);
}

void incrementTest()
{
  Serial.println("Spinning motor on channel A to full speed in increments");

  motorChannelA->moveForward();
  motorChannelA->disengageBrake();

  for(int speedStep = 0; speedStep <= 100; speedStep++)
  {
    motorChannelA->setSpeed(speedStep);

    delay(50);
  }

  Serial.println("Applying brake to channel A");

  motorChannelA->engageBrake();

  delay(1000);
}

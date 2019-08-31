#include "MotorChannel.h"

MotorChannel::MotorChannel(MotorChannelPinConfiguration pinConfiguration, int powerVoltage, int maxChannelVoltage)
{
  this->_pinConfiguration = pinConfiguration;
  this->_powerVoltage = powerVoltage;
  this->_maxChannelVoltage = maxChannelVoltage;

  pinMode(this->_pinConfiguration.DIRECTION_PIN, OUTPUT);
  pinMode(this->_pinConfiguration.BRAKE_PIN, OUTPUT);

  this->moveForward();
  this->engageBrake();
  this->setSpeed(0);
}

void MotorChannel::moveForward()
{
  digitalWrite(this->_pinConfiguration.DIRECTION_PIN, HIGH);
}

void MotorChannel::moveReverse()
{
  digitalWrite(this->_pinConfiguration.DIRECTION_PIN, LOW);
}

void MotorChannel::disengageBrake()
{
  digitalWrite(this->_pinConfiguration.BRAKE_PIN, LOW);
}

void MotorChannel::engageBrake()
{
  digitalWrite(this->_pinConfiguration.BRAKE_PIN, HIGH);
}

void MotorChannel::setSpeed(int speedPercentage)
{
  int speedStep = this->speedPercentagetoSpeedStep(speedPercentage);

  this->setSpeedStep(speedStep);
}

void MotorChannel::accelerateTo(int speedPercentage, int timeMillis)
{
  int desiredSpeedStep = this->speedPercentagetoSpeedStep(speedPercentage);

  if (desiredSpeedStep < this->_currentSpeed)
    return;

  float speedStepIncrease = (desiredSpeedStep - this->_currentSpeed) / (timeMillis / 50.0);

  int startTime = millis();

  float timeElapsed = 0.0;

  this->setSpeedStep(this->_currentSpeed + speedStepIncrease);

  while(timeElapsed < timeMillis)
  {
    delay(50); timeElapsed = timeElapsed + 50;

    this->setSpeedStep(this->_currentSpeed + speedStepIncrease);
  }

  int endTime = millis();

  Serial.println(endTime - startTime);
}

void MotorChannel::decelerateTo(int speedPercentage, int timeMillis)
{
}

void MotorChannel::setSpeedStep(int speedStep)
{
  if (speedStep > 255) speedStep = 255;
  if (speedStep < 0) speedStep = 0;
  
  this->_currentSpeed = speedStep;
  
  analogWrite(this->_pinConfiguration.SPEED_PIN, speedStep);
}

int MotorChannel::speedPercentagetoSpeedStep(int speedPercentage)
{
  if (speedPercentage > 100) speedPercentage = 100;
  if (speedPercentage < 0) speedPercentage = 0;

  float maxSpeedStep = 255.0 / (float)this->_powerVoltage * (float)this->_maxChannelVoltage;

  return static_cast<int>(maxSpeedStep * (float)speedPercentage / 100.0);
}

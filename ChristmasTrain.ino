#include "MotorChannel.h"
#include "LoggerFactory.h"
#include "Logger.h"
#include "SerialLogSink.h"

using namespace Logging;
using namespace MotorShield;


MotorChannel* motorChannel;

Logger *LOG = NULL;

void setup()
{
  Serial.begin(9600);

  LoggerFactory::initFactory(new SerialLogSink(), LogLevel::DEBUG);

  LOG = LoggerFactory::get()->createLogger("main", LogLevel::DEBUG);

  LOG->debug("Initializing Channel A of Motor Shield");

  motorChannel = new MotorChannel(ChannelAPinConfiguration, 12, 10);
}

void loop()
{
  forwardAndReverseTest();

  //incrementTest();
}

void forwardAndReverseTest()
{
  LOG->debug("Spinning motor on channel A at full speed in forward direction");

  motorChannel->moveForward();
  motorChannel->disengageBrake();
  motorChannel->setSpeed(100);

  delay(3000);

  LOG->debug("Applying brake to channel A");
  
  motorChannel->engageBrake();
  
  delay(3000);

  LOG->debug("Spinning motor on channel A at half speed in reverse direction");

  motorChannel->moveReverse();
  motorChannel->disengageBrake();
  motorChannel->setSpeed(50);
    
  delay(3000);

  LOG->debugf("Spinning motor on channel A to full speed over a period of %u seconds", 5);

  motorChannel->moveForward();
  motorChannel->disengageBrake();
  motorChannel->setSpeed(0);

  motorChannel->accelerateTo(100, 5000);
    
  delay(3000);

  LOG->debug("Applying brake to channel A");
  
  motorChannel->engageBrake();
  
  delay(2000);
}

void incrementTest()
{
  LOG->debug("Spinning motor on channel A to full speed in increments");

  motorChannel->moveForward();
  motorChannel->disengageBrake();

  for(int speedStep = 0; speedStep <= 100; speedStep++)
  {
    motorChannel->setSpeed(speedStep);

    delay(50);
  }

  LOG->debug("Applying brake to channel A");

  motorChannel->engageBrake();

  delay(1000);
}

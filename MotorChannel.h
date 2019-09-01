#ifndef MOTORSHIELD 
#define MOTORSHIELD

#include <Arduino.h>

#include "Logger.h"

namespace MotorShield
{
  struct ChannelPinConfiguration
  {
    int DIRECTION_PIN;
    int BRAKE_PIN;
    int SPEED_PIN;
  };

  const ChannelPinConfiguration ChannelAPinConfiguration = { 12, 9, 3 };

  class MotorChannel
  {
    protected:
      static Logging::Logger *LOG;
    
    public:
      MotorChannel(ChannelPinConfiguration pinConfiguration, int powerVoltage, int maxChannelVoltage);
  
    public:
      void moveForward();
      void moveReverse();
      void disengageBrake();
      void engageBrake();
      void setSpeed(int speedPercentage);
      void accelerateTo(int speedPercentage, int timeMillis);
      void decelerateTo(int speedPercentage, int timeMillis);
  
    private:
      void setSpeedStep(int speedStep);
      int speedPercentagetoSpeedStep(int speedPercentage);
    
    private:
      ChannelPinConfiguration _pinConfiguration;
      int _powerVoltage;
      int _maxChannelVoltage;
      int _currentSpeed;
  };
}

#endif 

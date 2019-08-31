#include <Arduino.h>

struct MotorChannelPinConfiguration
{
  int DIRECTION_PIN;
  int BRAKE_PIN;
  int SPEED_PIN;
};

const MotorChannelPinConfiguration ChannelAPinConfiguration = { 12, 9, 3 };

class MotorChannel
{
  public:
    MotorChannel(MotorChannelPinConfiguration pinConfiguration, int powerVoltage, int maxChannelVoltage);

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
    MotorChannelPinConfiguration _pinConfiguration;
    int _powerVoltage;
    int _maxChannelVoltage;
    int _currentSpeed;
};

#include <Arduino.h>

#include "LogLevel.h"
#include "SerialLogSink.h"

void Logging::SerialLogSink::writeLog(LogLevel logLevel, char const *loggerName, char const *message)
{
  unsigned long timestamp = millis();

  Serial.print(timestamp);
  Serial.print(" (");
  Serial.print(Logging::logLevelToLabel(logLevel));
  Serial.print(") - ");
  Serial.print(loggerName);
  Serial.print(" - ");
  Serial.println(message);
}

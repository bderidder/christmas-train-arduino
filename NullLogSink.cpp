#include "LogLevel.h"
#include "NullLogSink.h"

void Logging::SerialLogSink::writeLog(LogLevel logLevel, char const *loggerName, char const *message)
{
  // do nothing
}

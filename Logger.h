#ifndef LOGGER_H 
#define LOGGER_H

#include <Arduino.h>
#include "LogLevel.h"
#include "LogSink.h"

namespace Logging
{
  class Logger
  {
    public:
      Logger(LogSink *logSink, char const *name);
      Logger(LogSink *logSink, char const *name, Logging::LogLevel maxLogLevel);

    public:
      void warn(char const *message);
      void warnf(char const *format, ...);
    
      void debug(char const *message);
      void debugf(char const *format, ...);

      void writeLog(Logging::LogLevel logLevel, char const *message);
      void writeLogf(Logging::LogLevel logLevel, char const *format, ...);

    private:
      void init(LogSink *logSink, char const *name, Logging::LogLevel maxLogLevel);
      void internalWriteLogf(Logging::LogLevel logLevel, char const *format, va_list args);

    private:
      Logging::LogLevel _maxLogLevel;
      Logging::LogSink *_logSink;
      char const *_name;
  };
}

#endif 

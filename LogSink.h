#ifndef LOGSINK_H 
#define LOGSINK_H

#include "LogLevel.h"

namespace Logging
{
  class LogSink
  {
    public:
      virtual void writeLog(LogLevel logLevel, char const *loggerName, char const *message);
  };
}

#endif

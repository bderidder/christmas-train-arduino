#ifndef NULLLOGSINK_H 
#define NULLLOGSINK_H


#include "LogSink.h"

namespace Logging
{
  class NullLogSink : public LogSink
  {
    public:
      void writeLog(LogLevel logLevel, char const *loggerName, char const *message);
  };
}


#endif 

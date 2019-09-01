#ifndef SERIALLOGSINK_H 
#define SERIALLOGSINK_H


#include "LogSink.h"

namespace Logging
{
  class SerialLogSink : public LogSink
  {
    public:
      void writeLog(LogLevel logLevel, char const *loggerName, char const *message);
  };
}


#endif 

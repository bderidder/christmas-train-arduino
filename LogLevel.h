#ifndef LOGLEVEL_H 
#define LOGLEVEL_H

namespace Logging
{
  enum LogLevel
  {
    FATAL   = 0,
    ERROR   = 1,
    WARNING = 2,
    INFO    = 3,
    DEBUG   = 4,
    TRACE   = 5
  };

  char const *logLevelToLabel(Logging::LogLevel const &logLevel);
}

#endif 

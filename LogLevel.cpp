#include "LogLevel.h"

char const *Logging::logLevelToLabel(Logging::LogLevel const &logLevel)
  {
    switch(logLevel)
    {
      case Logging::LogLevel::FATAL   : return "FATAL";   break;
      case Logging::LogLevel::ERROR   : return "ERROR";   break;
      case Logging::LogLevel::WARNING : return "WARNING"; break;
      case Logging::LogLevel::INFO    : return "INFO";    break;
      case Logging::LogLevel::DEBUG   : return "DEBUG";   break;
      case Logging::LogLevel::TRACE   : return "TRACE";   break;
    }

    return "UNKNOWN";
  }

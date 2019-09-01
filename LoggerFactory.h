#ifndef LOGGINGFACTORY_H 
#define LOGGINGFACTORY_H

#include "LogLevel.h"
#include "Logger.h"

namespace Logging
{
  class LoggerFactory
  {
    public:
      static void initFactory(LogSink *defaultLogSink, LogLevel defaultMinLogLevel);

      static LoggerFactory* get();
    
      Logger* createLogger(char const *loggerName);
      Logger* createLogger(char const *loggerName, LogLevel minLogLevel);

    private:
      LoggerFactory(LogSink *defaultLogSink, LogLevel defaultMinLogLevel);
    
    private:
      static LoggerFactory *factoryInstance;

    private:
      LogSink *_defaultLogSink;
      LogLevel _defaultMinLogLevel;
  };
}

#endif 

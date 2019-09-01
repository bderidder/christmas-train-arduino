#include "LogLevel.h"
#include "LoggerFactory.h"
#include "Logger.h"

using namespace Logging;

LoggerFactory *LoggerFactory::factoryInstance = NULL;

LoggerFactory::LoggerFactory(LogSink *defaultLogSink, LogLevel defaultMinLogLevel)
{
  this->_defaultLogSink = defaultLogSink;
  this->_defaultMinLogLevel = defaultMinLogLevel;
}

void LoggerFactory::initFactory(LogSink *defaultLogSink, LogLevel defaultMinLogLevel)
{
  if (factoryInstance != NULL)
    return;

  factoryInstance = new LoggerFactory(defaultLogSink, defaultMinLogLevel);
}

LoggerFactory* LoggerFactory::get()
{
  return factoryInstance;
}

Logger* LoggerFactory::createLogger(char const *loggerName)
{
  return this->createLogger(loggerName, factoryInstance->_defaultMinLogLevel);
}

Logger* LoggerFactory::createLogger(char const *loggerName, Logging::LogLevel minLogLevel)
{
  return new Logger(this->_defaultLogSink, loggerName, minLogLevel);
}

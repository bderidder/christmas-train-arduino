#include "LogLevel.h"
#include "Logger.h"

using namespace Logging;

Logging::Logger::Logger(LogSink *logSink, char const *name)
{
  this->init(logSink, name, Logging::LogLevel::INFO);
}

Logging::Logger::Logger(LogSink *logSink, char const *name, Logging::LogLevel maxLogLevel)
{
  this->init(logSink, name, maxLogLevel);
}

void Logging::Logger::init(LogSink *logSink, char const *name, Logging::LogLevel maxLogLevel)
{
  this->_name = name;
  this->_logSink = logSink;
  this->_maxLogLevel = maxLogLevel;
}

void Logging::Logger::warn(char const *message)
{
  this->writeLog(Logging::LogLevel::WARNING, message);
}

void Logging::Logger::warnf(char const *format, ...)
{
  va_list args;

  va_start(args, format);
  
  this->internalWriteLogf(Logging::LogLevel::WARNING, format, args);

  va_end(args);
}

void Logging::Logger::debug(char const *message)
{
  this->writeLog(Logging::LogLevel::DEBUG, message);
}

void Logging::Logger::debugf(char const *format, ...)
{
  va_list args;

  va_start(args, format);
  
  this->internalWriteLogf(Logging::LogLevel::DEBUG, format, args);

  va_end(args);
}

void Logging::Logger::writeLog(Logging::LogLevel logLevel, char const *message)
{
  if (logLevel > this->_maxLogLevel)
    return;

  this->_logSink->writeLog(logLevel, this->_name, message);
}

void Logging::Logger::writeLogf(Logging::LogLevel logLevel, char const *format, ...)
{
  va_list args;
  va_start(args, format);

  this->internalWriteLogf(logLevel, format, args);
  
  va_end(args);
}

void Logging::Logger::internalWriteLogf(Logging::LogLevel logLevel, char const *format, va_list args)
{
  char buffer[512];
  vsprintf(buffer, format, args);

  this->writeLog(logLevel, buffer);
}

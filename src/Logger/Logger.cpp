#include "Logger.hpp"
#include <iostream>

namespace LCHS {

Logger::Logger(std::string filename, std::ostream& str) :
    std::ostream(&buffer), buffer(str, filename) {}

Logger::Logger(std::ostream& str) : std::ostream(&buffer), buffer(str) {}

Logger::~Logger() {}

void Logger::debug(const std::string& message) {
  buffer.setLogLevel(LogLevel::DEBUG);
  log(LogLevel::DEBUG, message);
  
}

void Logger::info(const std::string& message) {
  buffer.setLogLevel(LogLevel::INFO);
  log(LogLevel::INFO, message);
}

void Logger::error(const std::string& message) {
  buffer.setLogLevel(LogLevel::ERROR);
  log(LogLevel::ERROR, message);
}

void Logger::warning(const std::string& message) {
  buffer.setLogLevel(LogLevel::WARNING);
  log(LogLevel::WARNING, message);
}

void Logger::log(LogLevel level, const std::string& message) {
  buffer.setLogLevel(level);
  std::ostringstream logMessage;
  logMessage << message;

  // Output the log message
  *this << logMessage.str();
  this->flush();
}



void Logger::setLogLevel(LogLevel level) {
  logLevel = level;
}

}  // namespace LCHS
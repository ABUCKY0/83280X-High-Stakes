#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include "main.h"

namespace LCHS {

enum class LogLevel { DEBUG, INFO, ERROR, WARNING };

class Logger : public std::ostream {
  class MyStreamBuf : public std::stringbuf {
    std::ostream& output;
    std::string fn;            // store filename as a string
    bool logLevelSet = false;  // Flag to track if log level is set
    LogLevel currentLogLevel = LogLevel::INFO;  // Default log level

   public:
    MyStreamBuf(std::ostream& str, std::string& filename) :
        output(str), fn(filename) {
      fn = filename;
      std::cout << "Logger initialized with file: " << filename << this->fn
                << "," << std::endl;
    }
    MyStreamBuf(std::ostream& str) : output(str) {
      fn = "";
      std::cout << "Logger initialized with no file" << this->fn << ","
                << std::endl;
    }
    ~MyStreamBuf() {
      if (pbase() != pptr()) {
        putOutput();
      }
    }

    // When we sync the stream with the output.
    virtual int sync() override {
      putOutput();
      return 0;
    }

    void putOutput() {
      // Determine the log level prefix
      std::string logLevelStr;
      std::string color;
      if (logLevelSet) {
        switch (currentLogLevel) {
          case LogLevel::DEBUG:
            logLevelStr = "[DEBUG]";
            color = "\033[0;36m";  // Cyan
            break;
          case LogLevel::INFO:
            logLevelStr = "[INFO]";
            color = "\033[0m";  // Default
            break;
          case LogLevel::ERROR:
            logLevelStr = "[ERROR]";
            color = "\033[0;31m";  // Red
            break;
          case LogLevel::WARNING:
            logLevelStr = "[WARNING]";
            color = "\033[0;33m";  // Yellow
            break;
        }
      } else {
        logLevelStr = "[INFO]";
        color = "\033[0m";  // Default
      }

      // Output the message along with the current time.
      output << color << this->fn << " (" << pros::millis() << "ms) - " << logLevelStr << " " << str() << "\033[0m";
      str("");  // Clear the buffer
      logLevelSet = false;  // Reset the flag after output
    }

    void setLogLevel(LogLevel level) {
      currentLogLevel = level;
      logLevelSet = true;
    }
  };

 public:
  Logger(std::string filename, std::ostream& str);
  Logger(std::ostream& str);
  ~Logger();

  void debug(const std::string& message);
  void info(const std::string& message);
  void error(const std::string& message);
  void warning(const std::string& message);
  void log(LogLevel level, const std::string& message);

  // void flush();

  void setLogLevel(LogLevel level);

  // Override << and flush after each call
  template <typename T>
  Logger& operator<<(const T& value) {
    *static_cast<std::ostream*>(this) << value;
    // this->flush();
    return *this;
  }

  // Overload << to handle manipulators like std::endl
  Logger& operator<<(std::ostream& (*manip)(std::ostream&)) {
    *static_cast<std::ostream*>(this) << manip;
    this->flush();
    return *this;
  }

 private:
  MyStreamBuf buffer;
  LogLevel logLevel = LogLevel::INFO;  // Default log level
  std::optional<std::string> filename;
};

}  // namespace LCHS

#endif  // LOGGER_HPP
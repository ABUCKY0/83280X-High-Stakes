#include "Logger/Logger.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include "main.h"      // IWYU pragma: keep

LCHS::Logger::Logger() {}

void LCHS::Logger::log(const char* message, LogLevel level) {}
void LCHS::Logger::info(const char* message) {
  
}
void LCHS::Logger::warn(const char* message) {}
void LCHS::Logger::error(const char* message) {}
void LCHS::Logger::debug(const char* message) {}
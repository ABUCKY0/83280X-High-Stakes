namespace LCHS {
  enum class LogLevel {
    INFO,
    WARN,
    ERROR,
    DEBUG
  };
class Logger {
 public:
  Logger();

  void log(const char* message, LogLevel level);
  void info(const char* message);
  void warn(const char* message);
  void error(const char* message);
  void debug(const char* message);
};
}  // namespace LCHS
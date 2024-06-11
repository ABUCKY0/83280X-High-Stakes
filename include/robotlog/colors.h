#ifndef COLORS_H
#define COLORS_H

#include <string>
namespace ROBOTLOG {
class Colors {
 public:
  // Regular Colors
  static const std::string BLACK;
  static const std::string RED;
  static const std::string GREEN;
  static const std::string YELLOW;
  static const std::string BLUE;
  static const std::string MAGENTA;
  static const std::string CYAN;
  static const std::string WHITE;
  // Bold Colors
  static const std::string BOLD_BLACK;
  static const std::string BOLD_RED;
  static const std::string BOLD_GREEN;
  static const std::string BOLD_YELLOW;
  static const std::string BOLD_BLUE;
  static const std::string BOLD_MAGENTA;
  static const std::string BOLD_CYAN;
  static const std::string BOLD_WHITE;
  // Underline
  static const std::string UBLACK;
  static const std::string URED;
  static const std::string UGREEN;
  static const std::string UYELLOW;
  static const std::string UBLUE;
  static const std::string UMAGENTA;
  static const std::string UCYAN;
  static const std::string UWHITE;
  // Background
  static const std::string BG_BLACK;
  static const std::string BG_RED;
  static const std::string BG_GREEN;
  static const std::string BG_YELLOW;
  static const std::string BG_BLUE;
  static const std::string BG_MAGENTA;
  static const std::string BG_CYAN;
  static const std::string BG_WHITE;
  // High Intensity
  static const std::string HI_BLACK;
  static const std::string HI_RED;
  static const std::string HI_GREEN;
  static const std::string HI_YELLOW;
  static const std::string HI_BLUE;
  static const std::string HI_MAGENTA;
  static const std::string HI_CYAN;
  static const std::string HI_WHITE;
  // Bold High Intensity
  static const std::string BOLD_HI_BLACK;
  static const std::string BOLD_HI_RED;
  static const std::string BOLD_HI_GREEN;
  static const std::string BOLD_HI_YELLOW;
  static const std::string BOLD_HI_BLUE;
  static const std::string BOLD_HI_MAGENTA;
  static const std::string BOLD_HI_CYAN;
  static const std::string BOLD_HI_WHITE;
  // High Intensity backgrounds
  static const std::string HI_BG_BLACK;
  static const std::string HI_BG_RED;
  static const std::string HI_BG_GREEN;
  static const std::string HI_BG_YELLOW;
  static const std::string HI_BG_BLUE;
  static const std::string HI_BG_MAGENTA;
  static const std::string HI_BG_CYAN;
  static const std::string HI_BG_WHITE;
  // Reset
  static const std::string RESET;

  static std::string colorize(std::string color, std::string text) {
    return color + text + RESET;
  }
  static std::string CUSTOMRGB(short red, short green, short blue) {
    return "\033[38;2;" + std::to_string(red) + ";" + std::to_string(green) +
           ";" + std::to_string(blue) + "m";
  }
};

}  // namespace LOG
#endif
// Kaleb Robles
// kkrobles@csu.fullerton.edu
// @Kaleb16
// Partners: @HiepSolivan

#include "parking_functions.h"

bool CanParkOnAsh(const std::string& day, int hour) {
  if (day == "wed" && (hour >= 10 && hour < 12)) {
    return false;
  } else {
    return true;
  }
}

bool CanParkOnBeech(const std::string& day, int hour) {
  if (day == "fri" && (hour >= 8 && hour < 12)) {
    return false;
  } else {
    return true;
  }
}

bool CanParkOnCedar(const std::string& day, int hour) {
  if ((day == "tue" && hour >= 8 && hour < 10) || (hour >= 19 || hour < 7)) {
    return false;
  } else {
    return true;
  }
}

bool CanParkOnDate(const std::string& day, int hour, int min) {
  if (day == "sat" || day == "sun" ||
      ((day == "mon" || day == "tue" || day == "wed" || day == "thu" ||
        day == "fri") &&
       ((hour == 6 && min < 30) || (hour < 6) || (hour >= 16)))) {
    return true;
  } else {
    return false;
  }
}

bool CanParkOnElm(const std::string& day, int hour) {
  if ((day == "tue") ||
      ((day == "mon" || day == "wed" || day == "thu") &&
       (hour >= 8 && hour < 20)) ||
      ((day == "fri") && (hour >= 8 && hour < 17))) {
    return false;
  } else {
    return true;
  }
}
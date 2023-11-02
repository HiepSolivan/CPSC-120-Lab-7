// Kaleb Robles
// kkrobles@csu.fullerton.edu
// @Kaleb16
// Partners: @HiepSolivan

#include <iostream>
#include <string>
#include <vector>

#include "parking_functions.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};
  if (arguments.size() != 5) {
    std::cout << "error: you must supply four arguments"
              << "\n";
    return 1;
  }

  std::string street = arguments[1];
  std::string day = arguments[2];
  int hour = std::stoi(arguments[3]);
  int minute = std::stoi(arguments[4]);
  if (street != "ash" && street != "beech" && street != "cedar" &&
      street != "date" && street != "elm") {
    std::cout << "error: invalid street"
              << "\n";
    return 1;
  }
  if (day != "mon" && day != "tue" && day != "wed" && day != "thu" &&
      day != "fri" && day != "sat" && day != "sun") {
    std::cerr << "error: invalid day" << std::endl;
    return 1;
  }
  if (hour < 0 || hour > 23) {
    std::cerr << "error: invalid hour" << std::endl;
    return 1;
  }
  if (minute < 0 || minute > 59) {
    std::cerr << "error: invalid minute" << std::endl;
    return 1;
  }
  bool parking_allowed = true;

  if (street == "ash") {
    parking_allowed = CanParkOnAsh(day, hour);
  } else if (street == "beech") {
    parking_allowed = CanParkOnBeech(day, hour);
  } else if (street == "cedar") {
    parking_allowed = CanParkOnCedar(day, hour);
  } else if (street == "date") {
    parking_allowed = CanParkOnDate(day, hour, minute);
  } else if (street == "elm") {
    parking_allowed = CanParkOnElm(day, hour);
  }

  if (parking_allowed) {
    std::cout << "allowed\n";
  } else {
    std::cout << "not allowed\n";

    return 0;
  }

  return 0;
}
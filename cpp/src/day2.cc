#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

enum Token {
  Game,
  Red,
  Green,
  Blue
};

// read file and create vector separated on lines
std::vector<std::string> readFile(std::string fileName) {
  std::vector<std::string> input;
  std::ifstream inputFile(fileName);
  std::string line;
  while (std::getline(inputFile, line)) {
    input.push_back(line);
  }
  inputFile.close();
  return input;
}

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

int getMax(int a, int b) {
  return a > b ? a : b;
}

// Determine the games that would have been possible with 12 red, 13 green, and
// 14 blue
void partOne(const std::vector<std::string>& input,
             const int maxNumRed,
             const int maxNumGreen,
             const int maxNumBlue) {
  int sum = 0;
  for (auto line : input) {
    int numRed = 0;
    int numGreen = 0;
    int numBlue = 0;
    auto splitString = split(line, ' ');
    int gameId = 0;
    int nextVal = 0;
    bool wasGame = false;
    for (auto token : splitString) {
      if (token.find("Game") != std::string::npos) {
        wasGame = true;
      } else if (token.find("blue") != std::string::npos) {
        numBlue = getMax(numBlue, nextVal);
      } else if (token.find("green") != std::string::npos) {
        numGreen = getMax(numGreen, nextVal);
      } else if (token.find("red") != std::string::npos) {
        numRed = getMax(numRed, nextVal);
      } else {
        nextVal = stoi(token);
        if (wasGame) {
          gameId = nextVal;
          wasGame = false;
        }
      }
    }
    if (numRed > maxNumRed || numBlue > maxNumBlue || numGreen > maxNumGreen) {
      continue;
    }
    sum += gameId;
  }
  std::cout << "Sum of IDs: " << sum << std::endl;
}
void partTwo(const std::vector<std::string>& input) {
  int sum = 0;
  for (auto line : input) {
    int numRed = 0;
    int numGreen = 0;
    int numBlue = 0;
    auto splitString = split(line, ' ');
    int gameId = 0;
    int nextVal = 0;
    bool wasGame = false;
    for (auto token : splitString) {
      if (token.find("Game") != std::string::npos) {
        wasGame = true;
      } else if (token.find("blue") != std::string::npos) {
        numBlue = getMax(numBlue, nextVal);
      } else if (token.find("green") != std::string::npos) {
        numGreen = getMax(numGreen, nextVal);
      } else if (token.find("red") != std::string::npos) {
        numRed = getMax(numRed, nextVal);
      } else {
        nextVal = stoi(token);
        if (wasGame) {
          gameId = nextVal;
          wasGame = false;
        }
      }
    }
    sum += numRed * numGreen * numBlue;
  }
  std::cout << "Sum of Powers: " << sum << std::endl;
}

int main(void) {
  auto input = readFile("resources/aoc_day2.txt");
  partOne(input, 12, 13, 14);
  partTwo(input);
}

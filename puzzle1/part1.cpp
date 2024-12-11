#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  // Open the file for reading
  std::ifstream input("input.txt");

  // Confirm file opened
  if (!input.is_open()) {
    std::cerr << "| FAIL | Could not open the file" << std::endl;
    return 1;
  }

  // Storing data read from the file
  std::string line = "";
  std::vector<std::pair<int, int>> values;

  // Reading the file line by line to retrieve
  // the integer pair values
  while (std::getline(input, line)) {
    std::stringstream ss(line);
    int first, second;
    if (ss >> first >> second) {
      values.emplace_back(first, second);
    }
  }
  input.close();

  // Converting the pairs into individual vectors
  // to allow further operations
  std::vector<int> vectorOne, vectorTwo;
  for (const auto &pair : values) {
    vectorOne.push_back(pair.first);
    vectorTwo.push_back(pair.second);
  }

  // Sorting both arrays to allow the subtraction of
  // the smallest values to determine the overall
  // distance
  sort(vectorOne.begin(), vectorOne.end());
  sort(vectorTwo.begin(), vectorTwo.end());

  // Calculating the total difference between the values
  int totalDist = 0;
  for (size_t i = 0; i < vectorOne.size(); i++) {
    totalDist += std::abs(vectorOne[i] - vectorTwo[i]);
  }

  // Outputting the result to the terminal
  std::cout << "Total distance is: " << totalDist << std::endl;

  return 0;
}

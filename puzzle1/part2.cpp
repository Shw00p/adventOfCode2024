#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {

  // Open the file for reading
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cerr << "| FAIL | Could not open the file" << std::endl;
    return 1;
  }

  // Storing data read from the file
  std::string line;
  std::vector<std::pair<int, int>> values;

  // Reading the file line by line to retrieve
  // the integer pair values
  while (std::getline(input, line)) {
    std::stringstream data(line);
    int first, second;
    if (data >> first >> second) {
      values.emplace_back(first, second);
    } else {
      std::cerr << "| Warning | Unexpected data ignored" << std::endl;
    }
  }
  input.close();

  // Creating a frequency map from the second
  // column of data
  std::unordered_map<int, int> occurMap;
  for (const auto &pair : values) {
    occurMap[pair.second]++;
  }

  // The total is the sum of all values that exist
  // within column one, multiplied by how many times
  // they occur in column two
  int total = 0;
  for (const auto &pair : values) {
    total += pair.first * occurMap[pair.first];
  }

  // Outputting the result
  std::cout << "Total count is: " << total << std::endl;

  return 0;
}

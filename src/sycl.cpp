#include <iostream>
#include "kmp.h"

int main() {
    std::string checkingString;
    std::string sourceString;
    std::cin >> sourceString;
    std::cin >> checkingString;

    int result = CyclicShift(sourceString, checkingString);
    std::cout << result << std::endl;
  return 0;
}

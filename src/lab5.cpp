#include <iostream>
#include "kmp.h"


int main() {

    std::string text;
    std::string string;
    std::cin >> string;
    std::cin >> text;
    std::vector<int> result = SearchSubstring(text, string);
    std::cout << result[0];
    for (int i = 1; i < result.size(); i++) {
        std::cout << "," << result[i];
    }
    std::cout << std::endl;
    return 0;
}

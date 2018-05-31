
#ifndef KMP_H
#define KMP_H

#include <vector>
#include <string>

std::vector<int> PrefixF(std::string str);
std::vector<int> SearchSubstring(std::string string, std::string str);
int CyclicShift(std::string base_string, std::string sub_string);

#endif

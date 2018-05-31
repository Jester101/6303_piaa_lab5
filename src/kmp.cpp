#include <iostream>
#include <vector>
#include <string>

std::vector<int> PrefixF(std::string str) {
    int length = str.length();
    std::vector<int> digital_prefix(length);
    for (int i = 1; i < length; i++) {
        int j = digital_prefix[i -1];
        while (j > 0 && str[i] != str[j]) {
            j = digital_prefix[j - 1];
        }
        if (str[i] == str[j]) {
            ++j;
        }
        digital_prefix[i] = j;
    }
    return digital_prefix;
}


std::vector<int> SearchSubstring(std::string string, std::string str) {
    int strin_length = string.length();
    int str_length = str.length();
    std::vector<int> result;
    std::vector<int> prefix = PrefixF(str + "@" + string);
    for (int i = 0; i < prefix.size(); i++) {
        if(prefix[i] == str_length) {
            result.push_back(i - 2*str_length);
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    }
    return result;
}

int CyclicShift(std::string base_string, std::string sub_string) {

    int base_str_length = base_string.length();
    int sub_str_length = sub_string.length();

    if (base_str_length != sub_str_length)
        return -1;

    std::vector<int> prefix = PrefixF(sub_string);

    int base_index = 0;
    int sub_index = 0;

    while (base_index < (2 * base_str_length - 1)) {
        if (base_string[(base_index++ % base_str_length)] == sub_string[sub_index])
        {
            ++sub_index;
            if (sub_index == sub_str_length)
                return (base_index - sub_str_length);
        }
        else if (sub_index != 0)
        {
            --base_index;
            sub_index = prefix[sub_index - 1];
        }
    }

return -1;

}

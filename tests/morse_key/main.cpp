#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../morse_key.h"

typedef std::string str;

int main() {
    std::ifstream vowels_file;
    std::vector<MorseKey> morse_keys;

    vowels_file.open("vowels.txt");

    if (vowels_file.is_open()) {
        while (vowels_file.good()) {
            char utf8;
            str signals;

            bool success = true;

            vowels_file >> utf8 >> signals;

            MorseKey morse_key = MorseKey(utf8, signals, success);

            if (success) {
                morse_keys.push_back(morse_key);
            } else {
                std::cout << "Invalid Morse key, some signals are not valid\n";
            }
        }
    }

    // >>> perform testing of overloaded operators on MorseKey
    // == operator
    for (MorseKey morse_key : morse_keys) {
        if (morse_key == morse_key) {
            std::cout << "SUCCESS: " << morse_key.get_utf8() 
                      << " is equal to itself\n";
        } else {
            std::cout << "FAILED: comparison failed\n";
        }
    }

    // != operator
    // <<< perform testing of overloaded operators on MorseKey
}

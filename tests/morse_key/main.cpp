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

    // Remove duplicate data
    morse_keys.pop_back();

    // >>> perform testing of overloaded operators on MorseKey
    // == operator
    std::cout << "\nTESTS for == operator\n";

    for (MorseKey morse_key : morse_keys) {
        if (morse_key == morse_key) {
            std::cout << "SUCCESS: " << morse_key.get_utf8() 
                      << " is equal to itself\n";
        } else {
            std::cout << "FAILED: comparison failed\n";
        }
    }

    // != operator
    std::cout << "\nTESTS for != operator\n";

    MorseKey a = morse_keys[0];
    for (int i = 1; i < morse_keys.size(); i++) {
        if (a != morse_keys[i]) {
            std::cout << "SUCCESS: " << a.get_utf8()
                      << " is not equal to " << morse_keys[i].get_utf8()
                      << "\n";
        } else {
            std::cout << "FAILED: comparison failed\n";
        }
    }

    // < operator
    std::cout << "\nTESTS for < operator\n";

    MorseKey morse_key = morse_keys[0];
    for (int i = 1; i < morse_keys.size() - 1; i++) {
        if (morse_key < morse_keys[i]) {
            std::cout << "SUCCESS: " << morse_key.get_utf8()
                      << "'s Morse key is lower than " << morse_keys[i].get_utf8()
                      << "'s Morse key\n";
        } else {
            std::cout << "FAILED: comparison failed\n";
        }

        morse_key = morse_keys[i];
    }

    // > operator
    std::cout << "\nTESTS for > operator\n";

    morse_key = morse_keys[morse_keys.size() - 1];

    for (int i = morse_keys.size() - 2; i >= 0; i--) {
        if (morse_key > morse_keys[i]) {
            std::cout << "SUCCESS: " << morse_key.get_utf8()
                      << "'s Morse key is greater than " << morse_keys[i].get_utf8()
                      << "'s Morse key\n";
        } else {
            std::cout << "FAILED: comparison failed\n";
        }

        morse_key = morse_keys[i];
    }
    // <<< perform testing of overloaded operators on MorseKey
}

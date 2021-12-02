#include <iostream>
#include <string>
#include <vector>

#include "lib/morse_code.h"
#include "lib/morse_key.h"
#include "lib/morse_node.h"

typedef std::string str;

void add_utf8_translation(MorseCode&, std::vector<str>&, char);

int main() {
    str fname;

    std::cout << "Please type the Morse code standard you want to use"
              << " ('default' is the international standard): ";
    std::cin >> fname;

    MorseCode morse;

    if (fname == "default") {
        morse.read_morse_code("international_morse_code.txt");
    } else {
        morse.read_morse_code(fname);
    }

    if (morse.empty()) {
        std::cout << "Morse code is empty after attempt to read file!\n"
                  << "Closing interpreter\n";
        return 1;
    }

    std::cout << "Please insert your message: \n";

    std::vector<str> translation;
    char utf8;

    while(std::cin >> utf8 && std::cin.peek() != '\n') {
        add_utf8_translation(morse, translation, utf8);
    }

    // add again due to C++ buffer system
    add_utf8_translation(morse, translation, utf8);

    std::cout << "Your message in Morse code is:\n";

    for (str signals : translation) {
        std::cout << signals << " ";
    }

    std::cout << "\n";

    return 0;
}

void add_utf8_translation(MorseCode& morse, std::vector<str>& translation,
                          char utf8) {
    bool retrieved = true;
    str signals = morse.retrieve_by_utf8(utf8, retrieved);

    if (retrieved) {
        translation.push_back(signals);
    }

}

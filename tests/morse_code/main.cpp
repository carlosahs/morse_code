#include <iostream>
#include <string>

#include "../../morse_code.h"
#include "../../morse_node.h"
#include "../../morse_key.h"

int main() {
    MorseCode morse;

    // a vowels Morse code
    bool valid_morse = true;

    MorseKey a = MorseKey('a', "...", valid_morse);
    MorseKey e = MorseKey('e', ".._", valid_morse);
    MorseKey i = MorseKey('i', "._.", valid_morse);
    MorseKey o = MorseKey('o', ".__", valid_morse);
    MorseKey u = MorseKey('u', "_..", valid_morse);

    morse.add_key(a);
    morse.add_key(e);
    morse.add_key(i);
    morse.add_key(o);
    morse.add_key(u);

    morse.print_morse();

    // test removal
    morse.delete_key(a);
    morse.print_morse();

    // a consonants Morse code
    MorseKey b = MorseKey('b', "_._", valid_morse);
    MorseKey c = MorseKey('c', "__.", valid_morse);

    morse.add_key(b);
    morse.add_key(b);
    morse.add_key(c);

    morse.print_morse();

    // test clearing
    morse.clear();

    morse.print_morse();

    // test if file is read correctly
    morse.read_morse_code("international_morse_code.txt");
    morse.write_morse_code("international_morse_code_ordered.txt");

    morse.print_morse();

    // test retrieval of keys
    bool retrieved = true;
    std::string signals = morse.retrieve_by_utf8('a', retrieved);

    if (retrieved) {
        if (signals == "._") {
            std::cout << "SUCCESS: 'a' key was retrieved successfully\n";
        } else {
            std::cout << "FAILED: 'a' key was not retrieved successfully\n";
        }
    } else {
        std::cout << "FAILED: 'a' should be in Morse code\n";
    }

    retrieved = true;
    char utf8 = morse.retrieve_by_key("..._", retrieved);

    if (retrieved) {
        if (utf8 == 'v') {
            std::cout << "SUCCESS: '..._' corresponds to 'v' char\n";
        } else {
            std::cout << "FAILED: '..._' corresponds to a character that is not 'v'\n";
        }
    } else {
        std::cout << "FAILED: 'v' should've been retrieved\n";
    }

    retrieved = true;
    utf8 = morse.retrieve_by_key("_____", retrieved);

    if (retrieved) {
        if (utf8 == '0') {
            std::cout << "SUCCESS: '_____' corresponds to '0' char\n";
        } else {
            std::cout << "FAILED: '_____' corresponds to a character that is not '0'\n";
        }
    } else {
        std::cout << "FAILED: '0' should've been retrieved\n";
    }

    morse.delete_key(MorseKey('0', "_____", retrieved));
    signals = morse.retrieve_by_utf8('0', retrieved);

    if (retrieved) {
        std::cout << "FAILED: '0' should've been deleted\n";
    } else {
        std::cout << "SUCCESS: '0' has been deleted\n";
    }

    return 0;
}

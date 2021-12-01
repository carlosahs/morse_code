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

    // a consonants Morse code
    MorseKey b = MorseKey('b', "_._", valid_morse);
    MorseKey c = MorseKey('c', "__.", valid_morse);

    morse.add_key(b);
    morse.add_key(c);

    morse.print_morse();

    return 0;
}

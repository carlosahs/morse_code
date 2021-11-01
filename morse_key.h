#ifndef MORSE_KEY_H
#define MORSE_KEY_H

#include <string>

#define MORSE_KEY_LIMIT 8

/**
 * Defines the possible morse signals
 */
enum MorseSignal {
    DASH,
    DOT,
    NONE,
};

/** 
 * Describes the morse code representation of a UTF-8 enconded
 * symbol, identified by a 8-bit key
 */
class MorseKey {
    private:
        char utf8;
        MorseSignal key[MORSE_KEY_LIMIT] = { NONE };

        friend class MorseNode;
        friend class MorseCode;
    public:
        MorseKey();
        MorseKey(char, std::string);
        MorseKey(const MorseKey&);

        bool operator==(const MorseKey&);
        bool operator!=(const MorseKey&);
        bool operator>(const MorseKey&);
        bool operator<(const MorseKey&);
};

#endif

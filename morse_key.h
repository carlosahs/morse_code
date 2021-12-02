#ifndef MORSE_KEY_H
#define MORSE_KEY_H

#include <string>
#include <sstream>

#define MORSE_KEY_LIMIT 8

typedef std::string str;

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
        MorseSignal key[MORSE_KEY_LIMIT];

        bool equality_helper(const MorseKey& morse_key);

        void initialize_key();

        MorseKey(str);
        MorseKey(char, str);

        friend class MorseNode;
        friend class MorseCode;
    public:
        MorseKey();
        MorseKey(char, str, bool&);
        MorseKey(const MorseKey&);

        char get_utf8();

        str get_signals();

        bool operator==(const MorseKey&);
        bool operator!=(const MorseKey&);
        bool operator>(const MorseKey&);
        bool operator<(const MorseKey&);
};

#endif

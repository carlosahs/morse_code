#include "morse_key.h"

// >>> Constructor definitions
MorseKey::MorseKey() {
    utf8 = ' ';
}

MorseKey::MorseKey(char symbol, std::string signals) {
    utf8 = symbol;
    
    if (signals.size() <= MORSE_KEY_LIMIT && signals.size() > 0) {
        bool is_valid = true;

        for (int i = 0; i < signals.size(); i++) {
            switch (signals.at(i)) {
                case '.':
                    key[i] = DOT;
                    break;
                case '_':
                    key[i] = DASH;
                    break;
                default:
                    is_valid = false;
                    break;
            }

            if (!is_valid) {
                for (int j = 0; j < i; j++) {
                    key[j] = NONE;
                }
                break;
            }
        }
    }
}

MorseKey::MorseKey(const MorseKey& morse_key) {
    utf8 = morse_key.utf8;

    for (int i = 0; i < MORSE_KEY_LIMIT; i++) {
        key[i] = morse_key.key[i];
    }
}
// <<< Constructor definitions

bool MorseKey::operator==(const MorseKey& morse_key) {
    if (utf8 == morse_key.utf8) {
        for (int i = 0; i < MORSE_KEY_LIMIT; i++) {
            if (key[i] != morse_key.key[i]) {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool MorseKey::operator!=(const MorseKey& morse_key) {
    if (utf8 == morse_key.utf8) {
        for (int i = 0; i < MORSE_KEY_LIMIT; i++) {
            if (key[i] != morse_key.key[i]) {
                return true;
            }
        }

        return false;
    }

    return true;
}

bool MorseKey::operator>(const MorseKey& morse_key) {
    int nth_signal = 0;

    while (key[nth_signal] == morse_key.key[nth_signal]) {
        nth_signal++;

        if (nth_signal == MORSE_KEY_LIMIT) {
            return false;
        }
    }

    switch (key[nth_signal]) {
        case DOT:
            switch (morse_key.key[nth_signal]) {
                case DASH: case DOT:
                    return false;
                case NONE:
                    return true;
            }
        case DASH:
            return true;
        case NONE:
            return false;
    }
}

bool MorseKey::operator<(const MorseKey& morse_key) {
    int nth_signal = 0;

    while (key[nth_signal] == morse_key.key[nth_signal]) {
        nth_signal++;

        if (nth_signal == MORSE_KEY_LIMIT) {
            return false;
        }
    }

    switch (key[nth_signal]) {
        case DOT:
            switch (morse_key.key[nth_signal]) {
                case DASH:
                    return true;
                case DOT: case NONE:
                    return false;
            }
        case DASH:
            return false;
        case NONE:
            return true;
    }
}

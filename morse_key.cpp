#include "morse_key.h"

// >>> Constructor definitions
MorseKey::MorseKey() {
    utf8 = ' ';
}

MorseKey::MorseKey(std::string signals) {
    if (signals.size() <= MORSE_KEY_LIMIT && signals.size() > 0) {
        for (int i = 0; i < signals.size(); i++) {
            switch (signals.at(i)) {
                case '.':
                    key[i] = DOT;
                    break;
                case '_':
                    key[i] = DASH;
                    break;
                default:
                    break;
            }
        }
    }
}

MorseKey::MorseKey(char symbol, std::string signals) {
    utf8 = symbol;
    
    if (signals.size() <= MORSE_KEY_LIMIT && signals.size() > 0) {
        for (int i = 0; i < signals.size(); i++) {
            switch (signals.at(i)) {
                case '.':
                    key[i] = DOT;
                    break;
                case '_':
                    key[i] = DASH;
                    break;
                default:
                    break;
            }
        }
    }
}

MorseKey::MorseKey(char symbol, std::string signals, bool& success) {
    utf8 = symbol;
    
    if (signals.size() <= MORSE_KEY_LIMIT && signals.size() > 0) {
        for (int i = 0; i < signals.size(); i++) {
            switch (signals.at(i)) {
                case '.':
                    key[i] = DOT;
                    break;
                case '_':
                    key[i] = DASH;
                    break;
                default:
                    success = false;
                    break;
            }

            if (!success) {
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

// >>> private methods definition
bool MorseKey::equality_helper(const MorseKey& morse_key) {
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
// <<< private methods definition

// >>> public methods definitions
char MorseKey::get_utf8() {
    return utf8;
}

str MorseKey::get_signals() {
    str signals = "";

    for (int i = 0; i < MORSE_KEY_LIMIT; i++) {
        switch (key[i]) {
            case DASH:
                signals += "_";
                break;
            case DOT:
                signals += ".";
                break;
            case NONE:
                break;
        }
    }

    return signals;
}
// <<< public methods definitions

// >>> operator overloading definitions
bool MorseKey::operator==(const MorseKey& morse_key) {
    return equality_helper(morse_key);
}

bool MorseKey::operator!=(const MorseKey& morse_key) {
    return !equality_helper(morse_key);
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
// <<< operator overloading definitions

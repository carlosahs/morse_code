#ifndef INTERPRETER_UI_H
#define INTERPRETER_UI_H

#include <string>
#include <vector>

#include "lib/morse_code.h"

typedef std::string str;

class InterpreterUI {
    private:
        MorseCode morse;

        void menu();
    public:
        InterpreterUI();

        void char_to_morse_translation(char, std::vector<str>&);
        void morse_to_char_translation(str, std::vector<str>&);
        void start();
};

#endif

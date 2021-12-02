#ifndef INTERPRETER_UI_H
#define INTERPRETER_UI_H

#include <iostream>
#include <string>
#include <vector>

#include "lib/morse_code.h"

#define MAX_OPTION 5

typedef std::string str;
typedef unsigned int u32;

class InterpreterUI {
    private:
        MorseCode morse;

        void menu(u32&);
        void read_morse();
        void create_morse();
        void write_morse();
        void translate_utf8_to_morse();
        void translate_morse_to_utf8();
    public:
        InterpreterUI();

        void utf8_to_morse(char, std::vector<str>&);
        void morse_to_utf8(str, std::vector<char>&);
        void start();
};

#endif

#ifndef INTERPRETER_UI_H
#define INTERPRETER_UI_H

#include <iostream>
#include <string>
#include <vector>

#include "lib/morse_code.h"

typedef std::string str;
typedef unsigned int u32;

class InterpreterUI {
    private:
        MorseCode morse;

        void menu(u32&);
        void read_morse(str);
        void create_morse();
    public:
        InterpreterUI();

        void utf8_to_morse(char, std::vector<str>&);
        void morse_to_utf8(str, std::vector<char>&);
        void start();
};

#endif

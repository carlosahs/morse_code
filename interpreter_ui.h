#ifndef INTERPRETER_UI_H
#define INTERPRETER_UI_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "lib/morse_code.h"
#include "lib/morse_key.h"

#define MAX_OPTION 7

typedef std::string str;
typedef unsigned int u32;

const str DEFAULT_MORSE_FILE = "international_morse_code.txt";
const str DEFAULT_COMPARISON_FILE = "comparison_results.txt";

class InterpreterUI {
    private:
        MorseCode morse;

        void menu(u32&);
        void read_morse(bool&);
        void create_morse(bool&);
        void write_morse(bool&);
        void clear_morse();
        void compare_morse();
        void translate_utf8_to_morse();
        void translate_morse_to_utf8();
        void utf8_to_morse(char, std::vector<str>&);
        void morse_to_utf8(str, std::vector<char>&);
    public:
        InterpreterUI();

        void start();
};

#endif

#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "morse_key.h"
#include "morse_node.h"

typedef std::string str;

/**
 * Implements a BST to create a Morse code
 */
class MorseCode {
    private:
        MorseNode* root;

        std::unordered_map<char, str> utf8_to_key;

        void add(MorseKey, MorseNode*&);
        void left_rotate(MorseNode*&);
        void right_rotate(MorseNode*&);
        void delete_(MorseKey, MorseNode*&);
        void print(MorseNode*, str, bool);

        int max_height(int, int);
        int balance_factor(MorseNode*);
        int get_node_height(MorseNode*);

        MorseNode* min_key_node(MorseNode*);

        char retrieve(MorseKey&, MorseNode*, bool&);
    public:
        MorseCode();
        ~MorseCode();

        void add_key(MorseKey);
        void delete_key(MorseKey);
        void print_morse();
        void read_morse_code(str);
        void clear();

        str retrieve_by_utf8(char, bool&);

        char retrieve_by_key(str, bool&);

        bool empty();
};

#endif

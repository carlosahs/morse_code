#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <string>
#include <iostream>

#include "morse_key.h"
#include "morse_node.h"

typedef std::string str;

/**
 * Implements a BST to create a Morse code
 */
class MorseCode {
    private:
        MorseNode* root;

        void add(MorseKey, MorseNode*&);
        void left_rotate(MorseNode*&);
        void right_rotate(MorseNode*&);
        void delete_(MorseKey, MorseNode*&);
        void print(MorseNode*, str, bool);

        int max_height(int, int);
        int balance_factor(MorseNode*);
        int get_node_height(MorseNode*);

        MorseNode* min_key_node(MorseNode*);
    public:
        MorseCode();
        MorseCode(bool);
        MorseCode(const MorseCode&);
        ~MorseCode();

        void add_key(MorseKey);
        void delete_key(MorseKey);
        void print_morse();
};

#endif

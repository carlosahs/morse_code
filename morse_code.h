#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "morse_key.h"
#include "morse_node.h"

typedef unsigned int u32;

/**
 * Implements a BST to create a Morse code
 */
class MorseCode {
    private:
        MorseNode* root;

        bool retrieve(const MorseKey&, MorseNode*&);
        bool add(MorseKey, MorseNode*&);

        void left_rotate(MorseNode*&);
        void right_rotate(MorseNode*&);

        u32 max_height(u32, u32);
        u32 balance_factor(MorseNode*);
    public:
        MorseCode();
        MorseCode(bool);
        MorseCode(const MorseCode&);
        ~MorseCode();

        bool retrieve_key(const MorseKey&);
        bool add_key(MorseKey);
        bool delete_key(char);
        bool update_key(char);
};

#endif

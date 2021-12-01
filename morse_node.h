#ifndef MORSE_NODE_H
#define MORSE_NODE_H

#include "morse_key.h"

typedef unsigned int u32;

/**
 * Defines a bst-like node so that it is easier to define a custom
 * Morse code
 */
class MorseNode {
    private:
        MorseKey key;

        MorseNode* right;
        MorseNode* left;

        u32 height;

        friend class MorseCode;
    public:
        MorseNode();
        MorseNode(MorseKey);
        MorseNode(MorseKey, MorseNode*, MorseNode*);
        ~MorseNode();
};

#endif

#ifndef MORSE_NODE_H
#define MORSE_NODE_H

#include "morse_key.h"

/**
 * Defines a bst-like node so that it is easier to define a custom
 * Morse code
 */
class MorseNode {
    private:
        MorseKey key;
        MorseNode* parent;
        MorseNode* right;
        MorseNode* left;

        friend class MorseCode;
    public:
        MorseNode();
        MorseNode(MorseKey);
        MorseNode(MorseKey, MorseNode*, MorseNode*, MorseNode*);
};

#endif

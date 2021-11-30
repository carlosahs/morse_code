#include "morse_node.h"

MorseNode::MorseNode() {
    key.utf8 = ' '; // default root on any morse code

    parent = 0;
    right = 0;
    left = 0;
}

MorseNode::MorseNode(MorseKey morse_key) {
    key = morse_key;

    parent = 0;
    right = 0;
    left = 0;
}

MorseNode::MorseNode(MorseKey morse_key, 
                     MorseNode* parent_node,
                     MorseNode* left_node,
                     MorseNode* right_node) {
    key = morse_key;

    parent = parent_node;
    left = left_node;
    right = right_node;
}

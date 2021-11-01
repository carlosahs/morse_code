#include "morse_node.h"

MorseNode::MorseNode() {
    key.utf8 = ' '; // default root on any morse code
    right = 0;
    left = 0;
}

MorseNode::MorseNode(MorseKey morse_key) {
    key = morse_key;
    right = 0;
    left = 0;
}

MorseNode::MorseNode(MorseKey morse_key, 
                     MorseNode* left_node,
                     MorseNode* right_node) {
    key = morse_key;
    left = left_node;
    right = right_node;
}

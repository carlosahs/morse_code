#include "morse_code.h"

// >>> private methods
bool MorseCode::retrieve(const MorseKey& key, MorseNode*& node) {
    while (node != 0 && node->key != key) {
        if (node->key < key) {
            node = node->right;
        } else if (node->key > key) {
            node = node->left;
        }
    }

    if (node == 0) {
        return false;
    }

    return true;
}

bool MorseCode::add(MorseKey key, MorseNode*& node) {
    while (node != 0) {
        if (node->key < key) {
            node = node->right;
        } else if (node->key > key) {
            node = node->left;
        } else {
            return false; // duplicate morse keys are not allowed
        }
    }

    node = new MorseNode(key);

    return true;
}

void MorseCode::right_rotate(MorseNode*& y) {
    MorseNode* x = y->left;
    MorseNode* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max_height(y->left->height, y->right->height) + 1;
    x->height = max_height(x->left->height, x->right->height) + 1;

    y = x;
}

u32 MorseCode::max_height(u32 a, u32 b) {
    return (a > b) ? a : b;
}
// <<< private methods

// >>> public methods
bool MorseCode::retrieve_key(const MorseKey& key) {
    switch (key.key[0]) {
        case DOT:
            return retrieve(key, root->left);
        case DASH:
            return retrieve(key, root->right);
        case NONE: // this case is invalid
            return false;
    }
}

bool MorseCode::add_key(MorseKey key) {
    switch (key.key[0]) {
        case DOT:
            return add(key, root->left);
        case DASH:
            return add(key, root->right);
        case NONE: // cannot add key that starts with a NONE signal
            return false;
    }
}
// <<< public methods

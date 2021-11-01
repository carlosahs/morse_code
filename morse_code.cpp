#include "morse_code.h"

MorseCode::MorseCode() {
    root = new MorseNode();
}

bool MorseCode::retrieve(const MorseKey& key, MorseNode* node) {
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

bool MorseCode::add(MorseKey key, MorseNode* node) {
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

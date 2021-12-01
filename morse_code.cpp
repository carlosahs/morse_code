#include "morse_code.h"

// >>> private methods
void MorseCode::add(MorseKey key, MorseNode*& node) {
    if (node == 0) {
        node = new MorseNode(key);
    }

    if (key < node->key) {
        add(key, node->left);
    } else if (key > node->key) {
        add(key, node->right);
    } else if (key == node->key) {
        return; // it is not allowed to add repeated keys in Morse code
    }

    node->height = max_height(node->left->height, node->right->height) + 1;

    int factor = balance_factor(node);

    if (factor > 1) {
        if (key < node->left->key) {
            right_rotate(node);
        } else if (key > node->left->key) {
            left_rotate(node->left);
            right_rotate(node);
        }
    }

    if (factor < -1) {
        if (key > node->right->key) {
            left_rotate(node);
        } else if (key < node->right->key) {
            right_rotate(node->right);
            left_rotate(node);
        }
    }
}

void MorseCode::left_rotate(MorseNode*& y) {
    MorseNode* x = y->right;
    MorseNode* z = x->left;

    x->left = y;
    y->right = z;

    y->height = max_height(y->left->height, y->right->height) + 1;
    x->height = max_height(x->left->height, x->right->height) + 1;

    y = x;
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

void MorseCode::delete_(MorseNode*& node, MorseKey key) {
    if (node == 0) {
        return;
    }       

    if (key < node->key) {
        delete_(node->left, key);
    } else if (key > node->key) {
        delete_(node->right, key);
    } else {
        if ((node->left == 0) || (node->right == 0)) {
            MorseNode* copy = node->left == 0 ? node->right : node->left;

            if (copy == 0) {
                copy = node;
                node = 0;
            } else {
                *node = *copy;
            }

            delete copy;
        } else {
            MorseNode* min = min_key_node(root->right);

            node->key = min->key;
            delete_(node->right, min->key);

            delete min;
        }
    }

    if (node == 0) {
        return;
    }

    root->height = max_height(node->left->height, node->right->height);

    int factor = balance_factor(node);

    if (factor > 1) {
        if (balance_factor(node->left) >= 0) {
            right_rotate(node);
        } else {
            left_rotate(node->left);
            right_rotate(node);
        }
    }

    if (factor < -1) {
        if (balance_factor(node->right) <= 0) {
            left_rotate(node);
        } else {
            right_rotate(node->right);
            left_rotate(node);
        }
    }
}

int MorseCode::max_height(int a, int b) {
    return (a > b) ? a : b;
}

int MorseCode::balance_factor(MorseNode* node) {
    if (node == 0) {
        return 0;
    }

    return node->left->height - node->right->height;
}

MorseNode* MorseCode::min_key_node(MorseNode* node) {
    MorseNode* copy = node;

    while (copy->left != 0) {
        copy = copy->left;
    }

    return copy;
}
// <<< private methods

// >>> public methods
void MorseCode::add_key(MorseKey key) {
    add(key, root);
}
// <<< public methods

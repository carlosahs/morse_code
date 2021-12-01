#include "morse_code.h"

// >>> constructore definitions
MorseCode::MorseCode() {
    root = 0;
}

MorseCode::~MorseCode() {
    delete root;
}
// <<< constructore definitions

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

    node->height = max_height(get_node_height(node->left), 
                              get_node_height(node->right)) + 1;

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

    y->height = max_height(get_node_height(y->left),
                           get_node_height(y->right)) + 1;
    x->height = max_height(get_node_height(x->left), 
                           get_node_height(x->right)) + 1;

    y = x;
}

void MorseCode::right_rotate(MorseNode*& y) {
    MorseNode* x = y->left;
    MorseNode* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max_height(get_node_height(y->left), 
                           get_node_height(y->right)) + 1;
    x->height = max_height(get_node_height(x->left), 
                           get_node_height(x->right)) + 1;

    y = x;
}

void MorseCode::delete_(MorseKey key, MorseNode*& node) {
    if (node == 0) {
        return;
    }       

    if (key < node->key) {
        delete_(key, node->left);
    } else if (key > node->key) {
        delete_(key, node->right);
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
            delete_(min->key, node->right);

            delete min;
        }
    }

    if (node == 0) {
        return;
    }

    node->height = max_height(get_node_height(node->left), 
                              get_node_height(node->right)) + 1;

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

void MorseCode::print(MorseNode* node, str level, bool right_left) {
    if (node != 0) {
        std::cout << level;

        if (right_left) {
            std::cout << "R: ";
        } else {
            std::cout << "L: ";
        }

        level += "   ";

        std::cout << node->key.utf8 << "\n";

        print(node->left, level, false);
        print(node->right, level, true);
    }
}

void MorseCode::retrieve_key(char utf8, MorseNode* node) {
}

int MorseCode::max_height(int a, int b) {
    return (a > b) ? a : b;
}

int MorseCode::balance_factor(MorseNode* node) {
    if (node == 0) {
        return 0;
    }

    return get_node_height(node->left) - get_node_height(node->right);
}

int MorseCode::get_node_height(MorseNode* node) {
    if (node == 0) {
        return 0;
    }

    return node->height;
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

void MorseCode::delete_key(MorseKey key) {
    delete_(key, root);
}

void MorseCode::retrieve_by_utf8(char utf8) {
    retrieve(utf8, root);
}

void MorseCode::print_morse() {
    print(root, "", true);
}

void MorseCode::read_morse_code(str fname) {
    std::ifstream file_stream;

    file_stream.open(fname);

    if (file_stream.is_open()) {
        while (file_stream.good()) {
            char utf8;
            str signals;

            bool is_valid = true;

            file_stream >> utf8 >> signals;

            MorseKey morse_key = MorseKey(utf8, signals, is_valid);

            if (is_valid) {
                add(morse_key, root);
            } else {
                std::cout << "Morse key contains invalid signals!\n";
            }
        }
    } else {
        std::cout << "Failed to open file\n";
    }
}
// <<< public methods

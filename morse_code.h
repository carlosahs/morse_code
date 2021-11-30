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

        u32 root_idx;

        bool retrieve(const MorseKey&, MorseNode*&);
        bool add(MorseKey, MorseNode*&);

        void rotate(MorseNode*&, MorseNode*&);
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

/**
 * (1) O -> 1, 0
 * (2) O -> 2, 1
 *      \
 *       O
 *     O
 *    /
 *   O
 * (3) O -> 3, 1
 *    /
 *   O
 *  /
 * O
 *    O
 *   / \
 *  O   O
 * (4)     O -> 4, 2
 *        / \
 *       O   O
 *      / 
 *     O   
 * (5)    O -> 5, 2
 *       / \
 *      O   O
 *     /
 *    O
 *   /
 *  O
 *
 *      O
 *     / \
 *    O   O
 *   / \
 *  O   O
 *
 * (6)  O -> 6, 3
 *     / \
 *    O   O
 *   /   / \
 *  O   O   O
 * (7)    O -> 7, 3
 *       / \
 *      O   O
 *     / \   \
 *    O   O   O
 *   /
 *  O
 *
 *  (P1)     O                   O
 *          / \\\\\             / \\\\\
 *         O       O           O       O
 *        / \     / \         / \     / \
 *       O   O   O   O ->    O   O   O   O
 *          / \                 /     \
 *         O   O               O       O
 *  (P2)      O                 O
 *           / \\\\\           / \\\\\\\
 *          O       O         O         O
 *         / \     / \       / \\\     / \
 *        O   O   O   O ->  O     O   O   O
 *           /   / \         \   /     \
 *          O   O   O         O O       O
*
*
 * Root:
*    Left:
*      Left:
*        Left
*        Right
*      Right
*    Right:
*      Right
 * Rotate cases:
 * (1)   O         O
 *      / \       / 
 *     O   O ->  O
 *    /         / \
 *   O         O   O
 * (2)   O        O
 *      / \      /
 *     O   O -> O
 *      \      / \
 *       O    O   O
 * (3)   O         O
 *      / \       /
 *     O   O ->  O
 *    / \       / \
 *   O   O     O   O
 *                  \
 *                   O
 * (4)    O          O
 *       / \        / 
 *      O   O ->   O  
 *     / \        / \
 *    O   O      O   O
 *   /          /     \
 *  O          O       O
 * (5)    O          O
 *       / \        / 
 *      O   O ->   O  
 *     / \        / \
 *    O   O      O   O
 *   / \        / \
 *  O   O      O   O
 */


#endif

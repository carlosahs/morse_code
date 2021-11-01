# Morse code generator
This program allows you to create your own morse code system or easily use the
standard Morse code.

The program operates using an AVL binary search tree that orders each of the Morse
symbols added by the user and those specified by the international Morse code.
The AVL binary search tree is required since it is important that the tree is
completely balanced so that the Morse symbols are correctly layout and quickly
accessed with a time complexity of `O(n * log n)`.

# Inspiration
https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees

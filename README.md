This program allows you to create your own morse code system or easily use the
standard Morse code.

The program operates using an AVL binary search tree that orders each of the Morse
symbols added by the user and those specified by the international Morse code.
The AVL binary search tree is required since it is important that the tree is
completely balanced so that the Morse symbols are correctly layout and quickly
accessed with a time complexity of `O(n * log n)`.

# Morse code interpreter
This program allows the user to translate a message in plain english to Morse code.

## Compilation instructions
From the root directory run
```
g++ -std=c++14 -O2 interpreter.cpp interpreter_ui.cpp lib/*.cpp
./a.out
```

## Usage
The interpreter is able to read a file containing a Morse code standard and then be 
able to translate from English to that Morse code standard.

To create your own Morse code standard simply copy `internation_morse_code.txt` to
a `txt` file and modify the Morse keys.

# Morse code translator

# Data structures I used
## `MorseCode`
I implemented an AVL tree so that the structure of any Morse code is balanced as it
should be. The implementation of this tree also helps to get `O(lg n)` time on 
insertion, deletion, and search operations.

The code allows a user to access a Morse key by a string of signals in `O(lg n)` time, 
while it also allows them to retrieve a Morse key by a character in `O(1)` time. The 
latter is achieved by implementing a hash map (`std::unordered_map`). But, why 
implement a hash map to retrieve a Morse key by a character and then an AVL tree to
retrieve a Morse key a string of Morse code? This decision was made to:
1. Identify attempts to insert a Morse key with the same character but a different
   Morse code into the tree in `O(1)` time.
2. The purpose of storing the Morse code in an AVL tree by a string of Morse code is 
   to give it structure and order, so that in this way the value of a character can be
   defined according to the user and not too much on the actual numeric value of the 
   character.

## `interpreter` program
This program simply uses a `vector` to store the words that need to be translated. The
choice of using this structure is because inserting items takes `O(1)` time, contrary to
a linked list where insertion takes `O(n)` time.


# Tests
## `MorseKey`
To compile and run the tests for `MorseKey`, from the root directory run
```
cd tests/morse_key/
g++ -std=c++14 -O2 main.cpp ../../lib/*.cpp
./a.out
```

## `MorseCode`
To compile and run the tests for `MorseCode`, from the root directory run
```
cd tests/morse_code/
g++ -std=c++14 -O2 main.cpp ../../lib/morse_key.cpp
./a.out
```

# Inspiration
https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees

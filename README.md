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
g++ -std=c++14 -O2 interpreter.cpp morse_key.cpp morse_node.cpp morse_code.cpp -o interpreter
./interpreter
```

## Usage
The interpreter is able to read a file containing a Morse code standard and then be 
able to translate from English to that Morse code standard.

To create your own Morse code standard simply copy `internation_morse_code.txt` to
a `txt` file and modify the Morse keys.

# Morse code translator

# Data structures I used

# Tests
## `MorseKey`
To compile and run the tests for `MorseKey`, from the root directory run
```
cd tests/morse_key/
g++ -std=c++14 -O2 main.cpp ../../morse_key.cpp
./a.out
```

## `MorseCode`
To compile and run the tests for `MorseCode`, from the root directory run
```
cd tests/morse_code/
g++ -std=c++14 -O2 main.cpp ../../morse_key.cpp ../../morse_node.cpp ../../morse_code.cpp
./a.out
```

# Inspiration
https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees

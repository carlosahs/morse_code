# Morse code
This program provides utilities to write a custom Morse code, read a Morse code from
a file, and write a Morse code to a file. It achieves this by storing the Morse code
in an AVL tree so that each value can be assigned a custom order.

# Morse code interpreter
This program allows the user to translate a message in plain english to Morse code.

## Compilation instructions
From the root directory run
```
g++ -std=c++14 -O2 interpreter.cpp interpreter_ui.cpp lib/*.cpp
./a.out
```

## Usage
After running the program, it will display a menu from which the user can select the
options that finds useful.

# Data structures I used
## `MorseCode`
The Morse code was implemented using an AVL tree so that the tree is the most
balanced, this is because it allows for insertion, deletion, and search operations
in `O(lg n)`. Additionally the structure of a balanced tree helps to the organization
of a Morse code standard.

Furthermore, `MorseCode` also implements a growable hash map through the 
`std::unordered_map` C++ STL API. The decision to use this structure was made according
to the following points:
* The use of a hash maps helps identify duplicate Morse keys that have the same utf8
  character but a different morse signal, thus avoiding the Morse code to have duplicate
  values. Implementing this without the use of a hash map makes code more difficult.
* `MorseCode` inserts Morse keys according to a comparison between their signals
  (with the exception of the `==` and `!=` operators that also compare the utf8 
  character). Because of this, retrieving a Morse key by character is harder, since the
  tree is implemented so that retrieval is performed with a Morse signal, hence using
  a hash map solves this issue.
* The latter point can be refuted by proposing the use of only hash maps for both the
  retrieval of Morse keys by character and by Morse signal. However, doing this 
  destroys the structure of the Morse code, making it impossible to determine how
  a Morse key can be compared with another.

  For example, the international Morse code standard assigns the `._` Morse signal to
  `a`, `_...` to `b`, `_._.` to `c` and so on according to the standard. Intuitively,
  the ordering may appear to be `a`, `b`, `c`, and so on. However, if
  this standard is ordered, in fact the first character is `e` with a Morse signal of
  `.` and second is `i` with a Morse signal of `..`. Thus, implementing an AVL tree
  gives structure to the Morse code and offers relatively fast insertion, deletion, 
  and searching `O(lg n)` times compared to the `O(1)` times of a hash map.

## `InterpreterUI` program
The program implements a `vector` when performing translation operations. The decision
to use a `vector` was made based on the following advantages it has over `list`:
* It uses less memory, so it is more convenient to use to store the data the user
  wants to translate, which consist of a sentence in most cases.
* For a relatively small number of elements, `vector` is faster than `list` in 
  searching and insertion operations, which take `O(1)` time.

### `compare_morse` method
Sorting is implemented in this method to correctly identify the characters that 
are part of two Morse codes, similar to the union of a set in mathematics. The 
sorting is performed by C++ STL `std::sort` API on a vector of characters and it has 
a time complexity of `O(n lg n)`.

The union of the Morse codes is performed in `O(n + m)` time using 
this code:
```cpp
// identify all the characters that are the same in both arrays
for (u32 i = 0; i < morse_utf8s.size(); i++) {
    for (u32 j = s_point; j < cmp_utf8s.size(); j++) {
        if (morse_utf8s[i] < cmp_utf8s[j]) {
            s_point = j;
            break;
        } else if (morse_utf8s[i] == cmp_utf8s[j]) {
            same_utf8s.push_back(morse_utf8s[i]);
            s_point = j + 1;
            break;
        } else if (morse_utf8s[i] > cmp_utf8s[j]) {
            // do nothing
        }
    }
}
```

The time complexity of the above algorithm is `O(n + m)` because it compares two
arrays of size `n` and `m` by iterating over the array in the inner loop just `m`
times by keeping track of the last index where the two arrays had the same value.
Due to the former, the inner loop actually iterates over its array only once, while
the outer loop simply iterates over the `n` elements of its array.

# Tests
## `MorseKey`
To compile and run the tests for `MorseKey`, from the root directory run
```
cd tests/morse_key/
g++ -std=c++14 -O2 main.cpp ../../lib/morse_key.cpp
./a.out
```

## `MorseCode`
To compile and run the tests for `MorseCode`, from the root directory run
```
cd tests/morse_code/
g++ -std=c++14 -O2 main.cpp ../../lib/*.cpp
./a.out
```

# Inspiration
https://stackoverflow.com/questions/2130416/what-are-the-applications-of-binary-trees

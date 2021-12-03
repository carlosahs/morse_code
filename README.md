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
ones that finds useful.

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
to use a `vector` was made based on its average insertion time of `O(1)` because of its 
implementation: Using regular C++ arrays that are replaced by larger ones when the 
current array is filled, copying each element of the filled array to the new larger
array, taking `O(n)` time. Another consideration was that since any message the user
enters is probably not going to be considerably large, then the `O(n)` operation of
`vector` when filled is an acceptable time complexity.

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

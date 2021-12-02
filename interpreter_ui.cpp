#include "interpreter_ui.h"

// >>> constructor definitions
InterpreterUI::InterpreterUI() {
    morse = MorseCode();
}
// <<< constructor definitions


// >>> private methods
void InterpreterUI::menu(u32& option) {
    option = 0;

    while (true) {
        std::cout << "(0) Close interpreter\n";
        std::cout << "(1) Read Morse code from file\n";
        std::cout << "(2) Create Morse code manually\n";
        std::cout << "(3) Write Morse code to file\n";
        std::cout << "(4) Translate message from utf8 to Morse code\n";
        std::cout << "(5) Translate message from Morse code to utf8\n";

        std::cin >> option;

        if (option > MAX_OPTION) {
            std::cout << "Invalid option, select a valid option please\n";
        } else {
            break;
        }
    }
}
// <<< private methods

// >>> public methods
void InterpreterUI::utf8_to_morse(char utf8, std::vector<str>& message) {
    bool retrieved = true;
    str morse_signal = morse.retrieve_by_utf8(utf8, retrieved);

    if (retrieved) {
        message.push_back(morse_signal);
    } else {
        std::cout << utf8 << " is not part of this Morse code\n";
        std::cout << "Marking as '?', message will be translated incorrectly\n";

        message.push_back("?");
    }
}

void InterpreterUI::morse_to_utf8(str morse_signal, std::vector<char>& message) {
    bool retrieved = true;
    char utf8 = morse.retrieve_by_key(morse_signal, retrieved);

    if (retrieved) {
        message.push_back(utf8);
    } else {
        std::cout << morse_signal << " is not part of this Morse code\n";
        std::cout << "Marking as '?', message will be translated incorrectly\n";

        message.push_back('?');
    }
}

void InterpreterUI::start() {
    u32 option = 1;

    while (option != 0) {
        menu(option);

        switch (option) {
            case 1:
            case 2:
            case 3:
            default:
                break;
        }
    }
}
// <<< public methods 

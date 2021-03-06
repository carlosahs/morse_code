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
        std::cout << "(6) Clear Morse code\n";
        std::cout << "(7) Compare Morse code\n";

        std::cin >> option;

        if (option > MAX_OPTION) {
            std::cout << "Invalid option, select a valid option please\n";
        } else {
            break;
        }
    }
}

void InterpreterUI::read_morse(bool& success) {
    str fname;

    std::cout << "(If you type 'default', the program will load "
              << "the international Morse code)\n";
    std::cout << "Please enter name of file containing Morse code "
              << "(e.g. 'my_morse.txt'):\n";
    std::cin >> fname;

    if (fname == "default") {
        std::cout << "...Reading '" << DEFAULT_MORSE_FILE << "' file\n";
        morse.read_morse_code(DEFAULT_MORSE_FILE);
    } else {
        std::cout << "...Reading '" << fname << "' file\n";
        morse.read_morse_code(fname);
    }

    // file either does not exist or is empty
    if (morse.empty()) {
        success = false;
    }
}

void InterpreterUI::create_morse(bool& success) {
    bool create_another = true;

    while (create_another) {
        std::cout << "Type utf-8 char followed by a Morse signal "
                  << "(e.g. 'a .._.'): \n";

        char utf8;
        str morse_signal;

        std::cin >> utf8 >> morse_signal;

        bool is_valid = true;
        MorseKey key = MorseKey(utf8, morse_signal, is_valid);

        if (is_valid) {
            std::cout << "...Adding " << utf8 << " "
                      << morse_signal << " Morse key\n";
            morse.add_key(key);
        } else {
            std::cout << "WARNING: The " << morse_signal
                      << " Morse signal is not valid\n";
            std::cout << "...It will NOT be added to the Morse code\n";

            success = false;
        }

        std::cout << "Do you want to add another Morse key?\n";
        std::cout << "(Type 'yes' if affirmative, else type 'no')\n";

        str user_answer;
        std::cin >> user_answer;

        if (user_answer == "yes") {
            success = true;

            std::cout << "...Prepare to add another Morse key\n";
        } else if (user_answer == "no") {
            create_another = false;
        } else {
            create_another = false;

            std::cout << "...Your answer will be considered as 'no'\n";
        }
    }
}

void InterpreterUI::write_morse(bool& success) {
    if (morse.empty()) {
        success = false;

        std::cout << "WARNING: The Morse code is empty\n";
        std::cout << "...Nothing will be written\n";

        return;
    }

    std::cout << "Type name of file (e.g. 'my_morse.txt')\n";

    str fname;
    std::cin >> fname;

    morse.write_morse_code(fname);

    std::cout << "...File '" << fname << "' was written\n";
}

void InterpreterUI::clear_morse() {
    morse.clear();

    std::cout << "Morse code was cleared, now it is empty\n";
}

void InterpreterUI::compare_morse() {
    if (morse.empty()) {
        std::cout << "WARNING: Morse code is empty, "
                  << "comparison is not possible\n";
        return;
    }

    std::cout << "Enter name of the file containing Morse code "
              << "to compare (e.g. 'my_morse.txt'):\n";

    str fname;
    std::cin >> fname;

    MorseCode cmp_morse;
    cmp_morse.read_morse_code(fname);

    if (cmp_morse.empty()) {
        std::cout << "WARNING: File is empty or does not exists\n";
        std::cout << "...Comparison is not possible\n";

        return;
    }

    std::vector<char> morse_utf8s = morse.get_utf8s();
    std::vector<char> cmp_utf8s = cmp_morse.get_utf8s();

    // sort vectors
    std::sort(morse_utf8s.begin(), morse_utf8s.end());
    std::sort(cmp_utf8s.begin(), cmp_utf8s.end());

    std::vector<char> same_utf8s;
    u32 s_point = 0; // starting point

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

    std::ofstream file_stream;

    file_stream.open(DEFAULT_COMPARISON_FILE);

    for (char utf8 : same_utf8s) {
        file_stream << utf8 << "\n";
    }

    file_stream.close();

    std::cout << "Characters that are the same in both Morse codes "
              << "were written to '"
              << DEFAULT_COMPARISON_FILE
              << "' file\n";
}

void InterpreterUI::translate_utf8_to_morse() {
    if (morse.empty()) {
        std::cout << "WARNING: Morse code is empty, "
                  << "translations are not possible\n";
        return;
    }

    std::vector<str> message;
    char utf8;

    std::cout << "...Please type your message: \n";

    while (std::cin >> utf8 && std::cin.peek() != '\n') {
        utf8_to_morse(utf8, message);
    }

    utf8_to_morse(utf8, message);

    std::cout << "...Your message in Morse code is: \n";

    for (str morse_signal : message) {
        std::cout << morse_signal << " ";
    }

    std::cout << "\n";
}

void InterpreterUI::translate_morse_to_utf8() {
    if (morse.empty()) {
        std::cout << "WARNING: Morse code is empty, "
                  << "translations are not possible\n";
        return;
    }

    std::vector<char> message;
    str morse_signal;

    std::cout << "...Please type your message in Morse code: \n";

    while (std::cin >> morse_signal && std::cin.peek() != '\n') {
        morse_to_utf8(morse_signal, message);
    }

    morse_to_utf8(morse_signal, message);

    std::cout << "...Your message is translated as: \n";

    for (char utf8 : message) {
        std::cout << utf8 << " ";
    }

    std::cout << "\n";
}

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
// <<< private methods

// >>> public methods
void InterpreterUI::start() {
    u32 option = 1;

    while (option != 0) {
        menu(option);

        bool success = true;

        switch (option) {
            case 1:
                read_morse(success);
                break;
            case 2:
                create_morse(success);
                break;
            case 3:
                write_morse(success);
                break;
            case 4:
                translate_utf8_to_morse();
                break;
            case 5:
                translate_morse_to_utf8();
                break;
            case 6:
                clear_morse();
                break;
            case 7:
                compare_morse();
                break;
            default:
                break;
        }
    }
}
// <<< public methods 

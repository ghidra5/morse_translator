#include "MorseApp.hpp"
#include <iostream>
#include <vector>


void keyHandler(UINT KEY, DWORD delayHold, DWORD delayAfter) {
    keybd_event(KEY, 0, 0, 0);
    keybd_event(KEY, 0, KEYEVENTF_KEYUP, 0);
    Sleep(delayHold);
    keybd_event(KEY, 0, 0, 0);
    keybd_event(KEY, 0, KEYEVENTF_KEYUP, 0);
    Sleep(delayAfter);
}

void pressKeyInMorseRhythm(UINT key, std::string morseCodeText) {
    for (char c : morseCodeText) {
        int delay = morseCodeRhythm.at(c);

        if (c == ' ') {
            Sleep(delay);
        } else if (c == '/') {
            Sleep(delay);
        } else {
            keyHandler(key, delay, delay);
        }
        
    }

}

std::string translateToMorse(std::string inputString) {
    std::string morseCodeText;

    for (char c : inputString) {
        c = toupper(c);

        if (morseCode.find(c) != morseCode.end()) {
            std::string morseCodeAtC = morseCode.at(c);
            std::cout << c << " equal: " << morseCodeAtC << std::endl;
            morseCodeText.append(morseCodeAtC + " ");
        } else {
            std::cout << "Character " << c << " not found" << std::endl;
        }

    }

    if (!morseCodeText.empty()) {
        morseCodeText.pop_back();
    }
     
    std::cout << "\"" << inputString << "\"" << " is " << "\"" << morseCodeText << "\"" << std::endl;

    return morseCodeText;
}

std::string input(std::string msg) {
    std::string input;
    std::cout << msg;
    std::getline(std::cin, input);
    return input;
}

int main() {
    std::string userInput = input("Enter text to translate:\n>>");

    std::string morseCodeText = translateToMorse(userInput);

    pressKeyInMorseRhythm(SCROLLLOCK, morseCodeText);  // hardcode

    std::cout << "end" << std::endl;

    return 0;
}

#ifndef MORSEAPP_HPP
#define MORSEAPP_HPP

#include <windows.h>
#include <string>
#include <map>

const UINT CAPSLOCK = VK_CAPITAL;
const UINT SCROLLLOCK = VK_SCROLL;

const std::map<char, std::string> morseCode = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', "/"}
};

const std::map<char, int> morseCodeRhythm = {
    {'.', 100},   // Dot duration
    {'-', 300},   // Stick duration
    {' ', 300},   // Letter spacing
    {'/', 700}    // Word spacing
};


#endif

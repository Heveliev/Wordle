// add_letters.cpp -- converting a word into an array of structures describing each letter

#include <string>
#include <vector>

#include "../../Config.h"


std::vector<S_LetterInfo> add_letters(const std::string& word, const int& word_length)
{
    std::vector<S_LetterInfo> LettersData;
    if (word_length == 0 || word.empty()) return LettersData;

    LettersData.resize(word_length);


    for (short i = 0; i < word_length; i++)
    {
        LettersData[i].letter = word[i];
        LettersData[i].index = i;
    }

    return LettersData;
}
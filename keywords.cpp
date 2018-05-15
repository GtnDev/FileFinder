//
// Created by gaetan on 15/05/18.
//

#include "keywords.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

keywords::keywords() : m_file_location() {}

std::vector<std::string> keywords::getKeyWords(const std::string fileLocation) {
    std::vector<std::string> key_words;
    std::ifstream file(fileLocation);

    if(file)
    {
        std::string line;
        std::string pattern = "phrase";
        pattern += " ";

        while(getline(file, line)) // Envoie la ligne a la methode isMatch
        {
            key_words.push_back(line);
        }
    }
    else
    {
        std::cout << "ERROR: Impossible to read file." << std::endl;
    }

    return key_words;
}
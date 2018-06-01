//
// Created by gaetan on 15/05/18.
//

#include "keywords.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

keywords::keywords() : m_file_location() {}


std::vector<std::string> parseWord(const std::string stringToParse) {
    std::string delimiter = "\"";
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = stringToParse.find(delimiter, prev);
        if (pos == std::string::npos) pos = stringToParse.length();
        std::string token = stringToParse.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delimiter.length();
    }
    while (pos < stringToParse.length() && prev < stringToParse.length());
    return tokens;
}

std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

std::vector<std::string> keywords::getKeyWords(const std::string fileLocation) {
    std::vector<std::string> key_words;
//    std::ifstream file(fileLocation);
    std::fstream file(fileLocation);

    if(file)
    {
        std::string line;

//        while(getline(file, line))
//        {
//            key_words.push_back(line);
//        }
        GotoLine(file, 1);
        file >> line;
        key_words = parseWord(line);
    }
    else
    {
        std::cout << "ERROR: Impossible to read file." << std::endl;
    }

    return key_words;
}
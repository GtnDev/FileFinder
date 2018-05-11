//
// Created by gtn on 11/05/18.
//

#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <experimental/filesystem>

fileReader::fileReader() : m_path("/"), m_text(), m_pattern(), m_fileName() {}

std::vector<std::string> fileReader::getAllFilesRecursive(const std::string& path)
{

    std::vector<std::string> file_names ;

    using iterator = std::experimental::filesystem::recursive_directory_iterator ;
    for( iterator iter(path) ; iter != iterator {} ; ++iter ) {
        file_names.push_back( iter->path().string() ) ;
    }

    return file_names ;
}
bool fileReader::isMatch(const std::string& text, const std::string& pattern)
{
    return std::string::npos != text.find(pattern);
}

bool fileReader::grepFile(const char fileName[255])
{
    bool matching = false;
    std::ifstream fichier(fileName);

    if(fichier)
    {
        std::string line;

        while(getline(fichier, line))
        {
            if (isMatch(line, "phrase")) {
                std::cout << line << std::endl;
                matching = true;
            }
        }

        return matching;
    }
    else
    {
        std::cout << "ERROR: Impossible to read file." << std::endl;
    }
}
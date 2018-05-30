#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
#include <experimental/filesystem>

fileReader::fileReader() : m_path("/"), m_text(), m_pattern(), m_fileName(), m_keywords() {}

// Retourne un tableau contenant tous les fichier du répertoire cible
std::vector<std::string> fileReader::getAllFilesRecursive(const std::string& path)
{

    std::vector<std::string> file_names ;

    using iterator = std::experimental::filesystem::recursive_directory_iterator ;
    for( iterator iter(path) ; iter != iterator {} ; ++iter ) {
        file_names.push_back( iter->path().string() ) ;
    }

    return file_names ;
}

// Compare la ligne envoyé avec le pattern et retourne un booléen
bool fileReader::isMatch(const std::string& text, const std::string& pattern)
{
    //TODO changer les occurences trouvées pour qu'elles correspondent au mot exact
    std::regex r("("+pattern+")(.*)"); // the pattern \b matches a word boundary
    std::smatch m;

    return std::regex_search(text, m, r);
}

// Ouvre le fichier cible et le lis ligne par ligne
bool fileReader::grepFile(std::string fileName, std::vector<std::string> keywords)
{
    bool matching = false;
    std::ifstream fichier(fileName);

    if(fichier)
    {
        std::string line;

        while(getline(fichier, line)) // Envoie la ligne a la methode isMatch
        {
            for( const auto& fn : keywords ) {
                if (isMatch(line, fn)) {
                    std::cout << fn << '\n' << line << std::endl;
                    matching = true;
                }
                if (matching) break;
            }
            if (matching) break;
        }

        return matching;
    }
    else
    {
        std::cout << "ERROR: Impossible to read file." << std::endl;
    }
}
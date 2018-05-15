//TODO  - Récupérer les mots clefs a partir d'un fichier.
//TODO  - Trouver les mots exact.
//TODO  - Envoyer les noms entiers des fichiers trouvé dans un fichier temporaire ou une liste.
//TODO  - Faire une copie des fichiers trouvés.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <array>
#include <experimental/filesystem>
#include "fileReader.h"

namespace fs = std::experimental::filesystem;
using namespace std;

vector<string> getKeyWords(const string& fileLocation) {
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

int main()
{
    string inputDirectory = "";
    string keyWorksFile = "";

    while (inputDirectory == "") {
        cout << "Enter the directory where you want to find out matching case :\n>";
        getline(cin, inputDirectory);
    }

    while (keyWorksFile == "") {
        cout << "Enter the location of keywords file :\n>";
        getline(cin, keyWorksFile);
    }

    vector<string> keyWords = getKeyWords(keyWorksFile);
    for( const auto& fn : keyWords ) {
        cout << fn << '\n' ;
    }

    fileReader rf;

    const vector<string> file_list = rf.getAllFilesRecursive(inputDirectory) ;

    for( const auto& fn : file_list ) {
        if (rf.grepFile(fn, keyWords)) {
            cout << fn << '\n' ;
        }
    }

    return 0;
}
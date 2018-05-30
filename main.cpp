//TODO  - Parser les mots clefs récupérés.
//TODO  - Trouver les mots exact.
//TODO  - Eviter les redondances dans les fichiers trouvés.
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
#include "keywords.h"

namespace fs = std::experimental::filesystem;
using namespace std;

int main()
{
    string inputDirectory = "";
    string keyWorksFile = "";
    vector<string> matchingFiles;


    while (inputDirectory == "") {
        cout << "Enter the directory where you want to find out matching case :\n>";
        getline(cin, inputDirectory);
    }

    while (keyWorksFile == "") {
        cout << "Enter the location of keywords file :\n>";
        getline(cin, keyWorksFile);
    }

    keywords kw;

    vector<string> keyWords = kw.getKeyWords(keyWorksFile);
    for( const auto& fn : keyWords ) {
        cout << fn << '\n' ;
    }

    fileReader rf;

    const vector<string> file_list = rf.getAllFilesRecursive(inputDirectory) ;

    ofstream tempFile("tempMactchingFiles.txt", ios::out | ios::trunc);

    for( const auto& fn : file_list ) {
        if (rf.grepFile(fn, keyWords)) {
            tempFile << fn << "\n";
        }
    }

    return 0;
}
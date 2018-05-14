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

int main()
{
    string inputDirectory = "";

    while (inputDirectory == "") {
        cout << "Enter the directory where you want to find out matching case :\n>";
        getline(cin, inputDirectory);
    }

    fileReader rf;

    const vector<string> file_list = rf.getAllFilesRecursive(inputDirectory) ;

    for( const auto& fn : file_list ) {
        if (rf.grepFile(fn)) {
            cout << fn << '\n' ;
        }
    }

    return 0;
}
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

std::vector<std::string> get_all_files_recursive( const std::string& path )
{
    std::vector<std::string> file_names ;

    using iterator = fs::recursive_directory_iterator ;
    for( iterator iter(path) ; iter != iterator {} ; ++iter ) {
        file_names.push_back( iter->path().string() ) ;
    }

    return file_names ;
}

static bool is_match(const string& text, const string& pattern)
{
    return string::npos != text.find(pattern);
}

int grep_file(const char fileName[255]) {
    bool matching = false;
    ifstream fichier(fileName);

    if(fichier)
    {
        string line;

        while(getline(fichier, line))
        {
            if (is_match(line, "phrase")) {
                cout << line << endl;
                matching = true;
            }
        }

        return matching;
    }
    else
    {
        cout << "ERROR: Impossible to read file." << endl;
    }
}

int main()
{
//      const char nomFichier[255];
//
//     cin >> nomFichier;

    fileReader rf;

     if (rf.grepFile("/home/gtn/Documents/testFile.txt")) {
         cout << "occurence found" << endl;
     }

    const std::vector<std::string> file_list = rf.getAllFilesRecursive( "/home/gtn/Documents" ) ;

    for( const auto& fn : file_list ) {
        std::cout << fn << '\n' ;
    }

    return 0;
}
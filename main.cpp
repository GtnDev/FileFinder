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

    cout << "Enter the directory where you want to find out matching case :\n>";
    getline(cin, inputDirectory);

    fileReader rf;

    const vector<string> file_list = rf.getAllFilesRecursive(inputDirectory) ;

    for( const auto& fn : file_list ) {
        if (rf.grepFile(fn)) {
            cout << fn << '\n' ;
        }
    }

    return 0;
}
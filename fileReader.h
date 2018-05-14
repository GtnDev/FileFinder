#ifndef FLP_LINUX_FILEREADER_H
#define FLP_LINUX_FILEREADER_H

#include <iostream>
#include <string>
#include <vector>

class fileReader {
public:
    fileReader();
    std::vector<std::string> getAllFilesRecursive(const std::string& m_path);
    bool isMatch(const std::string& text, const std::string& m_pattern);
    bool grepFile(std::string m_fileName);
private:
    const std::string m_path;
    const std::string m_text;
    const std::string m_pattern;
    std::string m_fileName;
};


#endif //FLP_LINUX_FILEREADER_H

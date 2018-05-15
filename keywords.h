//
// Created by gaetan on 15/05/18.
//

#ifndef FLP_LINUX_KEYWORDS_H
#define FLP_LINUX_KEYWORDS_H

#include <iostream>
#include <string>
#include <vector>

class keywords {
public:
    keywords();
    std::vector<std::string> getKeyWords(const std::string m_file_location);
private:
    const std::string m_file_location;
};


#endif //FLP_LINUX_KEYWORDS_H

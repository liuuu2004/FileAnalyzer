#ifndef INCLUDE_PARSER_H_
#define INCLUDE_PARSER_H_

#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

class IncludeParser {
public:
    static std::unordered_map<std::string, std::vector<std::string>>
        parse_includes(const std::vector<std::filesystem::path> &files);
};

#endif

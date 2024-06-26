#include "../include/include_parser.h"
#include <fstream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::vector<std::string>> IncludeParser::parse_includes(const std::vector<fs::path> &files) {
    std::unordered_map<std::string, std::vector<std::string>> include_map;
    std::regex include_pattern(R"(#include\s*["<](.*)[">])");

    for (const auto &file : files) {
        std::ifstream infile(file);
        if (!infile.is_open()) {
            continue;
        }

        std::string line;
        std::vector<std::string> includes;
        while (std::getline(infile, line)) {
            std::smatch match;
            if (std::regex_search(line, match, include_pattern)) {
                includes.emplace_back(match[1].str());
            }
        }
        include_map[file.string()] = includes;
    }

    return include_map;
}
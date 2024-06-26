#include "../include/file_reader.h"
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> FileReader::get_all_files(const fs::path &root, const std::string &ext) {
    std::vector<fs::path> files;
    for (const auto &entry : fs::recursive_directory_iterator(root)) {
        if (entry.is_regular_file() && entry.path().extension() == ext) {
            files.emplace_back(entry.path());
        }
    }
    return files;
}
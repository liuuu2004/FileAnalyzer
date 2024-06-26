#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <filesystem>
#include <vector>
#include <string>

class FileReader {
public:
    static std::vector<std::filesystem::path> get_all_files(const std::filesystem::path &root,
                                                            const std::string &ext);
};

#endif  // FILE_READER_H_
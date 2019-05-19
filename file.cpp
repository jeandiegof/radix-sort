#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> read_words(std::ifstream& file_stream) {
    if (!file_stream.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return {};
    }

    std::string content;
    if (!std::getline(file_stream, content)) {
        std::cout << "Couldn't read file content" << std::endl;
        return {};
    }

    // put data into a stream
    std::stringstream data_stream(content);
    std::string buffer;
    std::vector<std::string> words;
    while (data_stream >> buffer) {
        words.push_back(buffer);
    }
    return words;
}

void save_words(std::vector<std::string>& words, std::string filename) {
    std::ofstream file;
    file.open(filename, std::ios::out);

    for (const auto& word : words) {
        if (!word.empty()) {
            file << word << " ";
        }
    }
    file.close();
}

void count_words(const std::vector<std::string>& strings, std::string const& filename) {
    std::ofstream file;
    file.open(filename, std::ios::out);

    std::string last_string;
    auto it = std::begin(strings);

    for (auto& string : strings) {
        if (string != last_string) {
            const auto occurrences = std::count(it, std::end(strings), string);
            //std::cout << string << ": " << (int)occurrences << std::endl;
            file << string << ": " << (int)occurrences << std::endl;
            last_string = string;
            it += occurrences;
        }
    }
    file.close();
}
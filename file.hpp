#pragma once
#include <vector>
#include <string>

std::vector<std::string> read_words(std::ifstream& file_stream);
void save_words(std::vector<std::string>& words, std::string filename);
void count_words(const std::vector<std::string>& strings, std::string const& filename);
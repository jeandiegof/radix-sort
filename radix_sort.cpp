#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "radix_sort.hpp"

size_t maximum(const std::vector<std::string>& vector) {
    size_t max = vector[0].size();
    for (unsigned int i = 0; i < vector.size(); ++i) {
        if (vector[i].size() > max) {
            max = vector[i].size();
        }
    }
    return max;
}

bool is_string_valid(const std::string& string) {
    // if (string.empty()) {
    //     return false;
    // }

    // for (auto i : string) {
    //     if (i < 65 || i > 90) {
    //         return false;
    //     }
    // }
    return true;
}

void radix_sort_msd(std::vector<std::string>& vector) {
    // maximum returns the size of the maximum string
    size_t max_lenght = maximum(vector);
    std::cout << "Maximum: \n" << (size_t) max_lenght << std::flush;

    // creates a buffer for couting sort
    std::vector<uint32_t> buffer(27, 0);
    // radix_sort isn't a in place algorithm, so we need an extra bucket
    std::vector<std::string> vector_copy(vector.size());
    
    for (unsigned int i = max_lenght; i > 0; i--) {
        // clear buffer
        // std::cout << "\nBuffer" << std::flush;
        for (auto& k : buffer) k = 0;
        
        // std::cout << "\nCouting" << std::flush;
        // counting sort for digit i
        for (const auto& x : vector) {
            if (is_string_valid(x)) {
                const uint8_t index = (x.size() < i) ? 0 : (x[i - 1] - 64);
                buffer[index]++;
            }
        }
        // accumulate
        // std::cout << "\nAccumulate" << std::flush;
        for (unsigned int i = 1; i < buffer.size(); ++i) {
            buffer[i] += buffer[i-1];
        }

        // ordenate for i
        // std::cout << "\nOrdenate for i" << std::flush;
        // v = {abc, fdf, asd, aefq};
        for (std::int32_t k = vector.size() - 1; k >= 0; k--) {
            // std::cout << "\n [" << (std::int32_t) k << "] " << vector[k] << std::flush;
            if (vector[k].size() < i) {
                // std::cout << " vector size < i" << std::flush;
                const auto index = buffer[0]--;
                vector_copy[index - 1] = vector[k];
            } else {
                // std::cout << " vector size >= i" << std::flush;
                const auto index = vector[k][i - 1] - 64; // 0 a 26
                // std::cout << " index = " << (int) index << std::flush;
                // std::cout << " buffer[index] = " << (int) buffer[index] << std::flush;
                vector_copy[buffer[index] - 1] = vector[k];
                buffer[index]--;
            }
        }
        // std::cout << "\nBefore copy\n" << std::flush;
        vector = vector_copy;
    }
}
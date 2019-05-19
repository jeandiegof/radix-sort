#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "file.hpp"
#include "radix_sort.hpp"

int main() {
    std::ifstream war_and_peace;
    war_and_peace.open("war_and_peace_clean.txt");
    std::vector<std::string> wap_words = read_words(war_and_peace);
    war_and_peace.close();

    std::ifstream frankestein;
    frankestein.open("frankestein_clean.txt");
    std::vector<std::string> f_words = read_words(frankestein);
    frankestein.close();

    std::cout << "War and peace words: " << wap_words.size() << std::endl;
    std::cout << "Frankestein words: " << f_words.size() << std::endl;

    radix_sort_msd(wap_words);
    radix_sort_msd(f_words);

    save_words(wap_words, "war_and_peace_ordenado.txt");
    save_words(f_words, "frankestein_ordenado.txt");

    std::cout << "Counting occurrences... " << std::endl;

    count_words(f_words, "frankestein_contagem.txt");
    std::cout << "Frankestein done." << std::endl;

    count_words(wap_words, "war_and_peace_contagem.txt");
    std::cout << "War and peace done." << std::endl;
}

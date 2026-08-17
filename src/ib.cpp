#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("billion_words.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return 1;
    }

    const std::string word = "word ";
    const long long count = 1000000000; // 1 billion

    for (long long i = 0; i < count; ++i) {
        file << word;
        if (i % 10000000 == 0) { // Just to show progress every 10M
            std::cout << i / 10000000 << "% done...\n";
        }
    }

    file.close();
    std::cout << "Finished writing 1 billion words.\n";
    return 0;
}

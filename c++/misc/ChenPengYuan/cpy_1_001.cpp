#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to split a sentence into words
vector<string> split(const string &sentence) {
    vector<string> words;
    string word;
    for (auto ch : sentence) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word.push_back(ch);
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main() {
    map<string, int> word_count;

    // Read a file
    ifstream file("example.txt");
    if (!file.is_open()) {
        cerr << "Fail to open the file.\n";
        return -1;
    }

    // Count the words
    string line;
    while (getline(file, line)) {
        auto words = split(line);
        for (const auto &word : words) {
            ++word_count[word];
        }
    }

    // Find the most frequent word
    pair<string, int> most_frequent;
    for (const auto &entry : word_count) {
        if (most_frequent.second < entry.second) {
            most_frequent = entry;
        }
    }

    cout << "Most frequent word: " << most_frequent.first << '\n';

    return 0;
}

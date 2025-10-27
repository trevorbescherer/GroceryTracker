#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

bool GroceryTracker::Init(const std::string& inputFilePath) {
    // Start from an empty frequency table.
    freqByItem_.clear();

    // Try to open the input file
    std::ifstream fin(inputFilePath);
    if (!fin.is_open()) {
        return false; // caller prints a message
    }

    // Read tokens. Each word is treated as one purchased item.
    std::string token;
    while (fin >> token) {
        ++freqByItem_[token];
    }

    // Write backup immediately at start.
    WriteBackup("frequency.dat");
    return true;
}

int GroceryTracker::GetCount(const std::string& item) const {
    // Look up the item in the map; return 0 if not found.
    std::map<std::string, int>::const_iterator it = freqByItem_.find(item);
    if (it == freqByItem_.end()) {
        return 0;
    }
    return it->second;
}

void GroceryTracker::PrintAllCounts() const {
    // Iterate through all pairs in alphabetical order.
    for (std::map<std::string, int>::const_iterator it = freqByItem_.begin();
        it != freqByItem_.end(); ++it) {
        std::cout << it->first << ' ' << it->second << '\n';
    }
}

void GroceryTracker::PrintHistogram(char symbol) const {
    // For each item, print is name followed by 'count' copies of the symbol
    for (std::map<std::string, int>::const_iterator it = freqByItem_.begin();
        it != freqByItem_.end(); ++it) {
        std::cout << it->first << ' ';
        for (int i = 0; i < it->second; ++i) {
            std::cout << symbol;
        }
        std::cout << '\n';
    }
}

bool GroceryTracker::WriteBackup(const std::string& backupFilePath) const {
    // Write frequency table to a text file for backup
    std::ofstream fout(backupFilePath);
    if (!fout.is_open()) {
        return false;
    }
    // Each line: "Item count"
    for (std::map<std::string, int>::const_iterator it = freqByItem_.begin();
        it != freqByItem_.end(); ++it) {
        fout << it->first << ' ' << it->second << '\n';
    }
    return true;
}

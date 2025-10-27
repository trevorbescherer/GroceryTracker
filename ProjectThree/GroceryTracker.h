#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
    // Reads the input file and builds the frequency table.
    // Initialize by loading from the input file. Returns true on success.
    bool Init(const std::string& inputFilePath);

    // Get exact frequency of an item (0 if not found).
    int GetCount(const std::string& item) const;

    // Print "Item count" for all items.
    void PrintAllCounts() const;

    // Print histogram lines like "Item *****".
    void PrintHistogram(char symbol = '*') const;

    // Write backup file "frequency.dat" as "Item count" lines.
    bool WriteBackup(const std::string& backupFilePath = "frequency.dat") const;

private:
    // Container that stores item names as keys and their counts as values.
    std::map<std::string, int> freqByItem_;
};

#endif // GROCERY_TRACKER_H

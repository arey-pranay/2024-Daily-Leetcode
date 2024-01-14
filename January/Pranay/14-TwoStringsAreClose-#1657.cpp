#include <unordered_map>
#include <set>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;

        // Maps to store character frequencies for each word
        unordered_map<char, int> freqMap1, freqMap2;

        // Sets to store unique characters in each word
        set<char> charSet1, charSet2;

        // Populate frequency maps and character sets for both words
        for (char c : word1) {
            freqMap1[c]++;
            charSet1.insert(c);
        }

        for (char c : word2) {
            freqMap2[c]++;
            charSet2.insert(c);
        }

        // Check if character sets are the same
        if (charSet1 != charSet2)
            return false;

        // Create vectors of character frequencies for both words
        vector<int> freqVec1, freqVec2;

        for (auto& entry : freqMap1) {
            freqVec1.push_back(entry.second);
        }

        for (auto& entry : freqMap2) {
            freqVec2.push_back(entry.second);
        }

        // Sort frequency vectors
        sort(freqVec1.begin(), freqVec1.end());
        sort(freqVec2.begin(), freqVec2.end());

        // Check if the sorted frequency vectors are the same
        return freqVec1 == freqVec2;
    }
};

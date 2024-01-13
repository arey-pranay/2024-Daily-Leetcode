#include <unordered_map>

class Solution {
public:
    int minSteps(string s, string t) {
        std::unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int count = 0;
        for (char c : t) {
            if (freq.find(c) != freq.end() && freq[c] > 0) {
                freq[c]--;
            } else {
                count++;
            }
        }

        return count;
    }
};

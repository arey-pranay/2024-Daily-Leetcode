#include <vector>
#include <algorithm>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 1;
        vector<int> occurrences;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1])
                count++;
            else {
                if (find(occurrences.begin(), occurrences.end(), count) != occurrences.end())
                    return false;
                occurrences.push_back(count);
                count = 1;
            }
        }

        // Check the last count
        return find(occurrences.begin(), occurrences.end(), count) == occurrences.end();
    }

};

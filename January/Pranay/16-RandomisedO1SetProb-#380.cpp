#include <unordered_set>
#include <vector>
#include <cstdlib>

class RandomizedSet {
public:
    std::unordered_set<int> RS;

    RandomizedSet() {
        RS.clear();
    }
    
    bool insert(int val) {
        if(RS.find(val) == RS.end()){
            RS.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = RS.find(val);
        if(it != RS.end()){
            RS.erase(it);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        int size = RS.size();
        int pos = rand() % size;
        auto it = RS.begin();
        std::advance(it, pos);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

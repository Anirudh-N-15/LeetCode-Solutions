class RandomizedSet {
public:
    unordered_set<int> uset;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(uset.find(val)!= uset.end()) return false ;

        else{
            uset.insert(val);
        }
    
        return true ;
    }
    
    bool remove(int val) {
        if(uset.find(val) == uset.end()) return false ;
        else{
            uset.erase(val);
        }

        return true ;
    }
    
    int getRandom() {
        vector<int> elem(uset.begin(), uset.end());
        int randIndex = rand() % elem.size();

        return elem[randIndex] ;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
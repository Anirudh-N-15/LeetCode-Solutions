class SmallestInfiniteSet {
public:
    set<int> minheap;

    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) {
            minheap.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = *(minheap.begin());
        minheap.erase(minheap.begin());
        return smallest;
    }
    
    void addBack(int num) {
        minheap.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
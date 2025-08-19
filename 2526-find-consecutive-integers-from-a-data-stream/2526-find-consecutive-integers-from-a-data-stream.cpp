class DataStream {
public:
    unordered_map<int,int> umap ;
    int count = 0;
    int key = 0;

    DataStream(int value, int k) {
        count = k;
        key = value ;
        umap[value] = 0;
    }
    
    bool consec(int num) {
        umap[num]++ ;
        if(num == key) {
            cout << umap[num] << " ";
            if(umap[num] >= count) {
                return true ;
            }
        } else {
            umap[key] = 0;
        }
        return false ;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
class FindSumPairs {
public:
    unordered_map<int,int> umap ;
    vector<int> nums1,nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(const int & num :nums2){
            umap[num]++ ;
        }
    }
    
    void add(int index, int val) {
        umap[nums2[index]]-- ;
        nums2[index] += val ;
        umap[nums2[index]]++ ;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(const int &num : nums1) {
            int other = tot - num ;
            if(umap.find(other) != umap.end()){
                cnt += umap[other];
            }
        }
        return cnt ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> umap;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq ;

        
        for(int & num : nums){
            umap[num]++ ;
        }

        for(auto it : umap) {
            pq.push({it.second,it.first});
        }

        while(k--){
            auto [freq,num] = pq.top();
            res.push_back(num);
            pq.pop();
        }
        return res ;
    }   
};
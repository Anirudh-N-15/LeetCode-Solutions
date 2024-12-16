class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        int n = nums.size() ;

        for(int i=0;i<n;++i){
            pq.push({nums[i],i});
        }

        for(int i=0;i<k;++i){
            auto top = pq.top() ;
            pq.pop();
            top.first = top.first * multiplier ;
            pq.push(top) ;
        }

        for(int i=0;i<n;++i){
            auto top = pq.top();
            pq.pop();
            nums[top.second] = top.first ;
        }

        return nums ;
    }
};
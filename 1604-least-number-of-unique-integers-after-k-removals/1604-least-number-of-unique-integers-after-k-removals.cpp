class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp ;
        for(const int &num : arr) {
            mp[num]++ ;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

        for(const auto &it : mp) {
            pq.push({it.second,it.first});
        }

        while(k > 0) {
            int freq = pq.top().first; 
            cout << pq.top().first << " " << pq.top().second << endl ;
            if(freq > k) {
                return pq.size() ;
            } else {
                k -= freq ;
                pq.pop() ;
            }
        }
        return pq.size() ;

    }
};
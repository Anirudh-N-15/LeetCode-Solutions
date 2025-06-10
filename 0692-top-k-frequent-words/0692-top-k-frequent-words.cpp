class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(const string &word : words) {
            freq[word]++ ;
        }

        auto comp = [](const pair<int,string> &a, const pair <int,string> &b) {
            if(a.first != b.first) return a.first > b.first ;
            return a.second < b.second ;
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(comp)> minHeap(comp);

        vector<string> ans ;
        for(const auto & [word, count] : freq) {
            minHeap.push({count,word});
            if(minHeap.size() > k) {
                minHeap.pop() ;
            }
        }

        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans ;
    }
};
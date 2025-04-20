class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int &num : answers) mp[num]++ ;

        int ans = 0;
        for(auto x : mp){
            double f = x.second;
            double p_c = x.first + 1;
            ans += (ceil(f/p_c) * p_c);
        }   
        return ans ;
    }
};
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedset ;
        int currentsum =0 ;
        int count = 0;

        for(int i=0;i<banned.size();++i){
            if(banned[i]<=n){
                bannedset.insert(banned[i]);
            }
        }
        int m = bannedset.size();

        for(int i=1;i<=n;++i){

            if(bannedset.find(i)==bannedset.end() && (currentsum + i) <= maxSum){
                count++ ;
                currentsum += i ;
            }
        }
        return count ;
    }
};
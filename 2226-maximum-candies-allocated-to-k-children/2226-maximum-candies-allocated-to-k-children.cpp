class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCandies = 0;
        
        for(int i=0;i<n;++i){
            if(candies[i] > maxCandies){
                maxCandies = candies[i];
            }
        }

        int left = 0, right = maxCandies;
        while(left < right){
            int mid = (left + right +1)/2 ;

            if(canGive(candies, k, mid)) {
                left = mid  ;
            }
            else{
                right = mid-1 ;
            }
        }
            
        return left ;
        
    }
private:
    bool canGive(vector<int> candies, long long k, int numCandies ){
        int n = candies.size();
        long long  maxChildren = 0;

        for(int i =0;i<n;++i){
            maxChildren += candies[i]/numCandies ;
        }

        return maxChildren >= k ;
    }    
};


// https://leetcode.com/discuss/study-guide/1529866/solving-kth-kind-of-problems

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        for(int i=1;i<n;++i) {
            if(ratings[i - 1] < ratings[i]){
                candies[i] = candies[i- 1] + 1;
            }
        }

        for(int i=n-2;i>=0;i--) {
            if(ratings[i+1] < ratings[i]) {
                candies[i] = max(candies[i],candies[i +1] + 1); // This is becuase it can lead to wrong updation in the second pass. Can be avoided if we use two arrays one for left traversal and one for right traversal.
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};
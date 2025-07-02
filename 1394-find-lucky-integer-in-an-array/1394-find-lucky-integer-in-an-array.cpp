class Solution {
public:
    int findLucky(vector<int>& arr) {
        int greatest = 0;
        for(const int &num : arr) {
            greatest = max(num,greatest);
        }
        vector<int> freq(greatest+1,0);
        int lucky = -1 ;

        for(int i=0;i<arr.size();i++) {
            freq[arr[i]]++ ;
        }

        for(int i=1;i<=greatest;i++) {
            if(i == freq[i]) {
                lucky = i ;
            }
        }
        return lucky ;
    }
};
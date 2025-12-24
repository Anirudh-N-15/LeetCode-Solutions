class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());

        int appleSum = accumulate(apple.begin(),apple.end(),0);
        int count = 0, capSum = 0;

        for(const int &cap : capacity) {
            if(capSum < appleSum) {
                count++ ;
                capSum += cap ;
            } else {
                break;
            }
        }
        return count ;
    }
};
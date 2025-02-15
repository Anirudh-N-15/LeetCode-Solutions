class Solution {
public:
    int minPartitions(string n) {
        char maxNum = '0';

        for(int i=0;i<n.size();++i) {
            if(n[i] > maxNum){
                maxNum = n[i];
            }
        }
        return maxNum - '0';
    }
};
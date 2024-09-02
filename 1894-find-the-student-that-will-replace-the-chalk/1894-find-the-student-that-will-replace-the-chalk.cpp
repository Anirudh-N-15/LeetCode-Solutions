class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        int i;
        for(i=0;i<chalk.size();++i){
            sum += chalk[i];
        }

        while( k >= sum){
            k -= sum ;
        }
        i=0;

        while(i<chalk.size() && chalk[i]<=k){
            k -= chalk[i];
            i++ ;
        }
        return i%(chalk.size()) ;
    }
};
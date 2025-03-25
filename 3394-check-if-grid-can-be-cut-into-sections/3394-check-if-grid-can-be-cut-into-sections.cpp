class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        int m = rec.size();
        
        map<int,int> mpx; //Prefix sum for x 
        map<int,int> mpy; //Prefix sum for y
        for(auto r : rec)
        {
            mpx[r[0]+1]++;
            mpy[r[1]+1]++;
            mpx[r[2]]--;
            mpy[r[3]]--;
        }
        int count1 = 0 , count2 = 0;
        int prefixSumX = 0, prefixSumY = 0;
        for(auto [c,val] : mpx)
        {
            prefixSumX += val;
            if(prefixSumX ==0) 
            {
                count1++;
            }
        }
        for(auto [c,val] : mpy)
        {
            prefixSumY += val;
            if( prefixSumY ==0){
                count2++;
            }
        }

        if(count1>2 || count2 >2)
        {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1,0); //Bcoz every no. is used twice except 1 
        vector<bool> used(n+1,false); //To track which no.s has been used
        backtrack(result,used,n,0);
        return result ;
    }
private:
    bool backtrack(vector<int>&result,vector<bool>&used,int n,int index) {
        while(index < result.size() && result[index]!=0) index++ ;

        if(index == result.size()) return true ;

        for(int i=n;i>=1;--i) {
            if(used[i]) continue ;

            int secondIndex = (i == 1) ? index : index + i;

            if(secondIndex < result.size() && result[secondIndex] == 0) {
                result[index] = result[secondIndex] = i;
                used[i] = true ;
                if(backtrack(result,used,n,index +1)) return true ;
                result[index] = result[secondIndex] = 0;
                used[i] = false ;
            }
        }
        return false ;
    }


};
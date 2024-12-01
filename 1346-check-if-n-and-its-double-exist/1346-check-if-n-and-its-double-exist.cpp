class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp ;

        for(int i : arr){
            mp[i]++ ;
        }

        if(mp[0]>=2){
            return true ;
        }

        for(int i=0;i<n;++i){
            if((mp[arr[i]*2] > 0 && arr[i]*2 != arr[i]) || (!arr[i]%2 && mp[arr[i]/2]>0 && arr[i]/2 != arr[i])){
                return true ;
            }
        }
        return false ;
    }
};
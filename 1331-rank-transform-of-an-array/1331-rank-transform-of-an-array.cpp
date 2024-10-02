class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <pair<int,int>> temp;

        for(int i=0;i<arr.size();++i){
            temp.push_back({arr[i],i});
        }

        sort(temp.begin(),temp.end());
        int rank = 1;

        for(int i=0;i<temp.size();++i){
            if(i > 0 && temp[i].first == temp[i-1].first){
                arr[temp[i].second] = arr[temp[i-1].second] ;
            }

            else{
                arr[temp[i].second] = rank ;
                rank++ ;
            }
        }

        return arr ;
    }
};
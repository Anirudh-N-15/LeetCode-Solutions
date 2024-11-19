class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int elem1 = -1 ,elem2 = -1 ;
        int count1 = 0 , count2 = 0 ;

        for(int i=0;i<n;++i){
            if(elem1 == arr[i]){
                count1++ ;
            }
            else if(elem2 == arr[i]){
                count2++ ;
            }
            else if(count1 == 0){
                elem1 = arr[i];
                count1++ ;
            }
            else if(count2 ==0){
                elem2 = arr[i] ;
                count2++ ;
            }
            else{
                count1-- ;
                count2-- ;
            }
        }
        vector<int> ans ;
        count1 = 0,count2 = 0;

        for(int elem : arr){
            if(elem1 == elem) count1++ ;
            else if(elem2 == elem) count2++ ;
        }

        if(count1 > n/3) ans.push_back(elem1);
        if(count2 > n/3 && elem1 != elem2) ans.push_back(elem2);

        if(ans.size()==2 && ans[0]>ans[1]){
            swap(ans[0],ans[1]);
        }

        return ans ;
    }
};
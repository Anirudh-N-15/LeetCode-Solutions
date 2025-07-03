//The min weight possible to start from is the max_element in the array and 
//the maximum weight possible is the sum of all elements in the array.

class Solution {
public:
    int givenDays(vector<int>& weights, int& days,int& capacity) {
        int currDays = 1, currWeight = 0;

        for(const int &weight : weights) {
            if(currWeight + weight <= capacity) {
                currWeight += weight ;
            } else {
                currDays++ ;
                currWeight = weight ;
            }
        }
        return currDays ;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0, end = 0;

        for(const int &weight : weights) {
            start = max(start,weight);
            end += weight ;
        }        

        while(start <= end) {
            int mid = start + (end - start)/2 ;

            if(givenDays(weights,days,mid) <= days) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start ;
    }
};
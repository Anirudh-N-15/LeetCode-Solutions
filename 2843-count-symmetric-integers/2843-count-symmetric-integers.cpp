class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0 ;
        for(int i = low; i <= high ; i++){
            string check = to_string(i);
            if(check.size() %2 != 0) continue ;

            int ptr1 = 0,ptr2 = check.size() - 1;
            int sum1 = 0, sum2 = 0;
            while(ptr1 < ptr2){
                sum1 += check[ptr1] - '0' ;
                sum2 += check[ptr2] - '0' ;
                ptr1++ ;
                ptr2-- ;
            }
            if(sum1 == sum2){
                count++ ;
            }
        }
        return count ;
    }
};
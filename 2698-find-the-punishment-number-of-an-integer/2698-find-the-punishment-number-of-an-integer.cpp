class Solution {
public:
    bool canPartition(int num, int target) {
        if(target < 0 || num < target) {
            return false ;
        }

        if(num == target) {
            return true ;
        }

        return canPartition(num/10, target-num % 10) || 
               canPartition(num/100, target-num % 100) ||
               canPartition(num/1000, target-num % 1000) ;  
    }


    int punishmentNumber(int n) {
        int punishmentNum = 0;

        for(int i=1;i<=n;++i){
            int squareNum= i*i ;

            if(canPartition(squareNum,i)){
                punishmentNum += squareNum ;
            }
        }
        return punishmentNum ;
    }
};
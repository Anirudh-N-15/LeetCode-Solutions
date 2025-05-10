class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(flowerbed[0] == 0 && flowerbed.size() ==1){
            return true ;
        }

        if(flowerbed[0] == 0 && n > 0 && flowerbed[1]!= 1){
            flowerbed[0] = 1;
            n-- ;
        }
        if(flowerbed[m-1] == 0 && n > 0 && flowerbed[m-2]!=1){
            flowerbed[m-1] =1;
            n-- ;
        }

        for(int i = 1; i < m-1; i++) {
            if(flowerbed[i]!=1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && n>0) {
                flowerbed[i] = 1;
                n-- ;
            }
        }

        return n==0 ? true : false ;
    }
};
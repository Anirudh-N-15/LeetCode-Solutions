int minBitFlips(int start, int goal) {
    int ans = start ^ goal ;
    unsigned int count=0 ;

    while(ans>0){
        count = count + (ans&1);
        ans = ans >> 1 ;
    }
    return count ;
}
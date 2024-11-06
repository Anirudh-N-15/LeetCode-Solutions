int max(int a,int b){
    return a > b ? a:b ;
}

int lengthOfLongestSubstring(char* s) {
    int maxlen = 0 ;
    int current =0 ;
    int charlist[256] = {0} ;

    for(int i=0;i<strlen(s);++i){
        current = max(charlist[s[i]],current);
        maxlen = max(maxlen,i-current+1);
        charlist[s[i]] = i+1 ;
    }
    return maxlen ;
}
class Solution {
public:
    int getLucky(string s, int k) {
        int sum =0;
        string number;
       
        for(int i=0;s[i]!='\0';++i){
            int val = s[i] - 'a' + 1;
            number += to_string(val);
        }   
        while(k>0){
            sum=0;
            
            for(int i=0;i<number.length();++i){
                sum += number[i] - '0';
            }
            number = to_string(sum);
            k-- ;
        }
        return stoi(number) ;
    }
};
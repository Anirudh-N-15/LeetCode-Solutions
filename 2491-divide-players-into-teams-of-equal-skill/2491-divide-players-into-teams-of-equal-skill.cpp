class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long target = 0 ;
        long long sum = 0;

        int ptr1 = 0 ,ptr2 = skill.size()-1 ;
        target = skill[ptr1] + skill[ptr2] ;

        while(ptr1<ptr2){
            if(target == skill[ptr1] + skill[ptr2]){
                sum += (skill[ptr1] * skill[ptr2]);
            }
            else{
                return -1 ;
            }

            ptr1++ ;
            ptr2-- ;
        }
        return sum ;
    }
};
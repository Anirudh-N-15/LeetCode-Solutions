class Solution {
public:
    int countVowelStrings(int n) {
        return recurse(n, 0, 0);
    }
    int recurse(int n, int size, int idx){
        if(size==n)return 1;
        if(idx==5)return 0;

        int take = recurse(n, size+1, idx);
        int non_take = recurse(n, size, idx+1);

        return take+non_take;
    }
};
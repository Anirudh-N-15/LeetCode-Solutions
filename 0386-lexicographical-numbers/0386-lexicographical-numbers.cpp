class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector <int> result ;

        for(int i=1;i<=9;++i){
            lexicalSort(i,result,n);
        }

        return result ;
    }

private:
    void lexicalSort(int curr,vector <int>& result,int n){
        if(curr > n) return ;

        result.push_back(curr);

        for(int i=0;i<10;++i){
            if((curr*10)+i > n) return ;
            lexicalSort(curr*10 +i, result, n);
        }
    }    
};
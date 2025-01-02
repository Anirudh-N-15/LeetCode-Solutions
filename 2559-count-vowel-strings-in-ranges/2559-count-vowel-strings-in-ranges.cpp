class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int m = words.size();
        vector<int> preproc(m+1,0);
        int count =0 ;
        preproc[0] = 0;

        for(int i=0;i<m;++i){
            if(('a' == *(words[i].begin())|| 'e' == *(words[i].begin())|| 'i' == *(words[i].begin())|| 'o' == *(words[i].begin())|| 'u' == *(words[i].begin()) ) && ('a' == *(words[i].end()-1)|| 'e' == *(words[i].end()-1)|| 'i' == *(words[i].end()-1)|| 'o' == *(words[i].end()-1)|| 'u' == *(words[i].end()-1))) {
                count++ ;
            }
            preproc[i+1] = count ;
            cout << preproc[i+1] << " " ;
        }

        for(int i=0;i<n;++i){
            if(queries[i][0] == 0){
                ans[i] = preproc[queries[i][1]+1] ;
            }
            else{
                ans[i] = preproc[queries[i][1]+1] - preproc[queries[i][0]];
            }
        }

        return ans;
    }
};
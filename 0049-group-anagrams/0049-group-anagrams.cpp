class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n,false);
        vector<vector<string>> ans;
        sort(strs.begin(),strs.end());

        for(int i=0;i<n;++i){
            if(visited[i] == true) continue;
            vector<string> res ;
            res.push_back(strs[i]);
            visited[i] = true;
            for(int j=i+1;j<n;++j){
                if(valid(strs[i],strs[j]) && visited[j]!= true){
                    res.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            ans.push_back(res);
        }

        return ans; 
    }
    bool valid(string str1,string str2){
        if(str1.size() != str2.size()) return false ;
        int n = str1.size();
        vector<int> count(26,0);

        for(const char &c : str1){
            count[c - 'a']++ ;
        }

        for(const char &c : str2){
            count[c - 'a']-- ;
        }

        for(int i=0;i<26;++i){
            if(count[i] != 0){
                return false ;
            }
        }
        return true ;
    }
};
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string str = s1 + " " + s2 ;

        map<string,int> mp ;
        vector<string> result ;

        stringstream s(str);
        string word ;

        while(s >> word){
            mp[word]++ ;
        }

        for(auto element : mp){
            if(element.second == 1){
                result.push_back(element.first);
            }
        }
        return result ;
    }
};
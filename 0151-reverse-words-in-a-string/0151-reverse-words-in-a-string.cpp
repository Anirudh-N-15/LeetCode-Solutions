class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(),words.end());

        string res = "";
        for(string str : words) {
            res += str + " " ;
        }
        res.erase(res.size()-1);

        return res ;
    }
};
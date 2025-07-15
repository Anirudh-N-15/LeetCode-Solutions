class Solution {
public:
    void solve(string& digits, vector<string>& ans,string build,vector<string>& phone,int index){
        int n = digits.size();
        if(index >= n){
            ans.push_back(build);
            return ;
        } 

        string curr = phone[digits[index] - '0'] ;
        for(int i=0;i<curr.size();i++) {
            build += curr[i] ;
            solve(digits,ans,build,phone,index+1);
            build.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {} ;

        vector<string> ans ;
        vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits, ans, "", phone, 0);
        return ans; 
    }
};
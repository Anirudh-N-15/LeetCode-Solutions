class Solution {
    unordered_map<string, vector<char>> mpp;

public:
    bool dfs(string bottom, int i, string temp) {
        
        if (bottom.size() == 1) return true;

        if (i == bottom.size() - 1) {
            string nextRow;
            return dfs(temp, 0, nextRow);
        }

        string key = bottom.substr(i, 2);

        for (char v : mpp[key]) {
            temp.push_back(v);             
            if (dfs(bottom, i + 1, temp))    
                return true;              
            temp.pop_back();               
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &a : allowed) {
            mpp[a.substr(0, 2)].push_back(a[2]);
        }

        string temp;
        return dfs(bottom, 0, temp);
    }
};
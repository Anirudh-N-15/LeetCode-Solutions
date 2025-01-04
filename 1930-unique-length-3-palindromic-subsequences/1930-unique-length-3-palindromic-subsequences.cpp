class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> mp;
        unordered_set<string> ans;

        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }

        for (auto &[ch, indices] : mp) {
            if (indices.size() < 2) {
                continue;
            }

            int first = indices.front();
            int last = indices.back();

            unordered_set<char> mid;
            for (int i = first + 1; i < last; ++i) {
                mid.insert(s[i]);
            }

            for (char m : mid) {
                ans.insert(string(1, ch) + m + ch);
            }
        }

        return ans.size();
    }
};

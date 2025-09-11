class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiouAEIOU";
        return vowels.find(ch) != string::npos;
    }

    string sortVowels(string s) {
        map<char, int> mp;
        string ans = "";

        for (const char& ch :s) {
            if (isVowel(ch)) {
                mp[ch]++;
            }
        }

        for (const char& ch : s) {
            if (!isVowel(ch)) {
                ans += ch;
            } else {
                for (auto& it : mp) {
                    char c = it.first;
                    ans += c;
                    it.second--;
                    if (it.second == 0) {
                        mp.erase(it.first);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isVowel(int x) {
        if(x==0 || x==4 || x==8 || x==14 || x==20) return true;
        return false;
    }
    long long countAllSubString(string word, int k) {
        long long ans=0;
        int n=word.size(), start=0, end=0, consonant=0;
        unordered_map<int,int> mp; // to store cnt of all the vowels
        while(end<n) { 
            if(isVowel(word[end]-'a')) mp[word[end]-'a']++;
            else consonant++;
            // when we have all the vowels & consonants cnt is >=k ---> so we update our ans & shrink the window.
            while(consonant>=k && mp[0]>0 && mp[4]>0 && mp[8]>0 && mp[14]>0 && mp[20]>0) {
                ans += n-end; // add all the substrings
                if(isVowel(word[start]-'a')) mp[word[start]-'a']--;
                else consonant--;
                start++;
            }
            end++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return (countAllSubString(word, k)-countAllSubString(word, k+1));
    }
};
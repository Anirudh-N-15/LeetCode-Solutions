class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> listWords(wordList.begin(),wordList.end());
        if(listWords.find(endWord) == listWords.end()) {
            return 0;
        }
        int count = 1;
        queue<pair<string,int>> q;
        q.push({beginWord,count});

        while(!q.empty()) {
            string curr = q.front().first;
            int currCount = q.front().second;
            q.pop();

            if(curr == endWord) {
                return currCount;
            }

            int size = curr.size();
            for(int i=0;i<size;i++) {
                char original = curr[i];
                for(char j = 'a';j <= 'z';j++) {
                   curr[i] = j;

                    if(listWords.find(curr) != listWords.end()) {
                        q.push({curr,currCount +1});
                        listWords.erase(curr);
                    }
                }
                curr[i] = original ;
            }
        }
        return 0;
    }
};
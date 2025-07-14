class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        int n = cards.size();
        unordered_map<int,int> cardIndexMap;

        for(int i=0;i<n;i++) {
            if(cardIndexMap.find(cards[i]) != cardIndexMap.end()) {
                int oldIndex = cardIndexMap[cards[i]];
                ans = min(ans, i- oldIndex + 1);
                cardIndexMap[cards[i]] = i;
            } else {
                cardIndexMap[cards[i]] = i;
            }
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> uset(bank.begin(), bank.end());
        if (uset.find(endGene) == uset.end()) {
            return -1;
        }
        int n = startGene.size();
        vector<char> genes = {'A', 'C', 'T', 'G'};
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while (!q.empty()) {
            auto [currGene, count] = q.front();
            q.pop();

            if (currGene == endGene) {
                return count;
            }

            for (int i = 0; i < n; i++) {
                char org = currGene[i];

                for (const char& ch : genes) {
                    if(ch == org) continue;
                    currGene[i] = ch;
                    if (uset.find(currGene) != uset.end()) {
                        q.push({currGene, count + 1});
                        uset.erase(currGene);
                    }
                }
                currGene[i] = org;
            }
        }
        return -1;
    }
};
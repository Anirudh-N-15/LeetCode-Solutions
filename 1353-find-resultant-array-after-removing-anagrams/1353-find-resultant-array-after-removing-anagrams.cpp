class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<bool> marked(n,0);
        vector<string> ans ;
        for(int i=0;i<n-1;i++) {
            string curr = words[i] ;
            sort(curr.begin(),curr.end());

            for(int j=i+1;j<n;j++) {
                string check = words[j] ;
                sort(check.begin(),check.end());

                if(curr == check && i == j -1 ) {
                    marked[j] = true ;
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(marked[i] != true) {
                ans.push_back(words[i]);
            }
        }
        return ans ;
    }
};
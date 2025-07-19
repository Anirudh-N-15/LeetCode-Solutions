class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> mainFolder;
        mainFolder.push_back(folder[0]);

        for (int i = 1; i < n; i++) {
            string currFolder = mainFolder.back();
            currFolder += '/' ;

            if(folder[i].compare(0,currFolder.size(),currFolder) != 0) {
                mainFolder.push_back(folder[i]);
            }
        }
        return mainFolder ;
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> dest ;

        for(auto path : paths) {
            dest[path[0]] = path[1] ;
        }

        for(auto path : paths) {
            if(dest.find(path[1]) == dest.end()) {
                return path[1] ;
            }
        }
        return " " ;
    }
};
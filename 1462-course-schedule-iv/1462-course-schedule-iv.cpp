class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
         set<pair<int, int>> prereqSet;
    
    // Insert the given prerequisites into the set
    for (const auto& prereq : prerequisites) {
        prereqSet.insert({prereq[0], prereq[1]});
    }

    // Floyd-Warshall logic to determine indirect prerequisites
    for (int k = 0; k < numCourses; k++) {
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                if (prereqSet.count({i, k}) && prereqSet.count({k, j})) {
                    prereqSet.insert({i, j});  // If i -> k and k -> j, then i -> j
                }
            }
        }
    }

    // Process each query and check if it exists in the set
    vector<bool> result;
    for (const auto& query : queries) {
        result.push_back(prereqSet.find({query[0], query[1]}) != prereqSet.end());
    }
    
    return result;
    }
};
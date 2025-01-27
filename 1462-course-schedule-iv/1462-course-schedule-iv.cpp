class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int m = queries.size();
        // constructing adj map for DAG
        // recording the in-degrees
        unordered_map<int, vector<int>> coursesAfter;
        vector<int> inDegree(numCourses,0);
        for(const vector<int> &ab: prerequisites){
            coursesAfter[ab[0]].push_back(ab[1]);
            inDegree[ab[1]]++;
        }
        // constructing toAnswer sheet
        unordered_map<int, vector<pair<int,int>>> toAnswer;// v, q_index
        for(int q=0;q<m;q++){
            toAnswer[queries[q][1]].push_back({queries[q][0], q});
        }
        // onion sort
        queue<int> courseToTake;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
            courseToTake.push(i);
            }
        }
        // answering sheet
        vector<bool> ans(m);
        unordered_map<int, unordered_set<int>> coursesBefore;
        while(!courseToTake.empty()){
            int curr = courseToTake.front();
            courseToTake.pop();
            // answering
            for(const pair<int, int> vq: toAnswer[curr]){
            if(coursesBefore[curr].find(vq.first)!=coursesBefore[curr].end()){
                // isPre
                ans[vq.second] = true;
            }
            else{
                ans[vq.second] = false;
            }
            }
            // migrating/merging
            // pushing new courses to take as needed
            for(const int &c:coursesAfter[curr]){
            coursesBefore[c].insert(coursesBefore[curr].begin(), coursesBefore[curr].end());
            coursesBefore[c].insert(curr);
            inDegree[c]--;
            if(inDegree[c]==0){
                courseToTake.push(c);
            }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1] ;
        });

        int totalTime = 0;
        int count = 0;

        for(int i=0;i<courses.size();i++) {
            if(totalTime + courses[i][0] <= courses[i][1]) {
                totalTime += courses[i][0] ;
                count++ ;
            }
        }
        return count ;
    }
};
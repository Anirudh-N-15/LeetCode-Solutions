class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        using t = tuple<double,int,int> ;
        priority_queue<t, vector<t>> pq ;

        for(auto &clas : classes) {
            int a = clas[0], b = clas[1];
            double gain = (double)(a+1) /(b+1) - (double)a/b ;
            pq.push({gain,a,b});
        }

        while(extraStudents--) {
            auto [gain, a, b] = pq.top();
            pq.pop();
            a++ , b++ ;
            double newGain = (double)(a+1) /(b+1) - (double)a/b ;

            pq.push({newGain,a,b}); 
        }

        double ans = 0.0;
        while(!pq.empty()) {
            auto [gain, a, b] = pq.top();
            pq.pop();

            ans += (double)a/b ;
        }
        int n = classes.size();
        return ans/n ;
    }
};
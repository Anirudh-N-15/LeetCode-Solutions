class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minimum=arrays[0][0],maximum = arrays[0].back(),max_distance=0 ;

        for(int i=1;i<arrays.size();++i)
        {
            max_distance = max(max_distance,abs(arrays[i].back()-minimum));
            max_distance = max(max_distance,abs(maximum - arrays[i][0]));
            minimum = min(minimum,arrays[i][0]);
            maximum = max(maximum,arrays[i].back());
        }

        return max_distance ;



    }
};
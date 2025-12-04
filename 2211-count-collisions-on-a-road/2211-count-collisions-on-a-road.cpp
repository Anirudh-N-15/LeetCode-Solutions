class Solution {
public:
    int countCollisions(string dirs) {
        int n = dirs.size();
        int left = 0, right = n - 1;

        while(left < n && dirs[left] == 'L') {
            left++ ;
        }
        while(right >= left && dirs[right] == 'R') {
            right-- ;
        }

        int ans = 0;
        for(int i=left;i<=right;i++) {
            if(dirs[i] != 'S') {
                ans++ ;
            }
        }
        return ans ;
    }
};
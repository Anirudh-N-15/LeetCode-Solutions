class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m =nums2.size() ;
        int res2 = nums2[0];
        int res1 = nums1[0];
        int res3 = 0;
        if((n%2)==0 && (m%2)==0) return 0 ;
        
        else if((n%2)!=0 && (m%2)==0){
            for(int i=1;i<m;++i) {
                res2 ^= nums2[i] ;
            }
            return res2 ;
        }

        else if((n%2)==0 && (m%2)!=0){
            for(int i=1;i<n;++i){
                res1 ^= nums1[i] ;
            }
            return res1 ;
        }

        else {
            for(int i=1;i<m;++i) {
                res2 ^= nums2[i] ;
            }
             for(int i=1;i<n;++i){
                res1 ^= nums1[i] ;
            }
            return res1 ^ res2 ;
        }
    }
};
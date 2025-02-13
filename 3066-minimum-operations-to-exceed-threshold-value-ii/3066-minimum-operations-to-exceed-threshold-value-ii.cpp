class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq ;

        for(int &num : nums) {
            if(num < k) {
                pq.push(num);
            }
        }
        int count = 0;

        while(!pq.empty()) {
            long long min1= pq.top(); pq.pop();
            count++ ;  
            if(pq.empty()) break ;
            long long min2 =pq.top(); pq.pop();

            long long num = (long long )min(min1,min2)*2 + (long long )max(min1,min2);

            if(num < k) 
                pq.push((int)num);
  
        }
        return count ;



    }
};
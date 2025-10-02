class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int currTime = 1;
        while(memory1 >= 0 && memory2 >= 0) {
            if(currTime > memory1 && currTime > memory2) break; 
            if(memory1 >= memory2) {
                memory1 -= currTime ;
            } else {
                memory2 -= currTime ;
            }
            currTime++ ;
        }
        return {currTime,memory1,memory2};
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size() ;
        vector<int> answer(n,0);
        int balls = 0,moves=0;

        for(int i=0;i<n;++i){
           answer[i] += moves ;
           balls += boxes[i] - '0' ;
           moves += balls ;
        }

        moves= 0, balls = 0;

        for(int i=n-1;i>=0;--i){
            answer[i] += moves ;
            balls += boxes[i] - '0' ;
            moves += balls ;
        }
        return answer ;
    }
};
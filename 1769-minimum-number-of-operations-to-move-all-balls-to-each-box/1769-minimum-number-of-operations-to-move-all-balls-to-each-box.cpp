class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = n=boxes.size();
        vector<int> answer(n,0);

        for(int i=0;i<n;++i){
            int count = 0 ;
            for(int j=0;j<n;++j){
                if(i==j) continue ;

                else if(boxes[j]=='1'){
                    count += abs(i-j);
                }
                else continue ;
            }
            answer[i] = count ;
        }
        return answer ;
    }
};
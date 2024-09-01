class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <long long> pq ;
        long long sum =0 ;

        for(int i=0;i<gifts.size();++i){
            pq.push(gifts[i]);
        }

        for(int i=0;i<k;++i){
            int num = pq.top();
            pq.pop();
            num = sqrt(num) ;
            pq.push(num);
        }

        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum ;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin(),gas.end(),0);
        int totalCost = accumulate(cost.begin(),cost.end(),0);

        if(totalGas < totalCost) return -1 ;

        int res = 0, tank = 0;
        for(int i=0;i<n;++i) {
            tank += gas[i] - cost[i] ;
            
            if(tank < 0) {
                tank = 0;
                res = i + 1;
            }
        }
        return res ;
    }
};
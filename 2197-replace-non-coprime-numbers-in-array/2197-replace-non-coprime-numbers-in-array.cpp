// x * y = lcm(x,y) * gcd(x,y)
// So, lcm(x,y) = (x * y)/gcd(x,y) 

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack ;

        for(int &num : nums) {
            while(!stack.empty()) {
                int top = stack.back();
                int gcd = __gcd(top,num);

                if(gcd == 1) break ;

                stack.pop_back();

                long long merged = (long long)top/gcd * num ;
                num = (int)merged ;
            }   
            stack.push_back(num) ;
        }
        return stack ;

        
    }
};
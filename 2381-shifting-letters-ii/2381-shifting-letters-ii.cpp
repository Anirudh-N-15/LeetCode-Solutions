class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        int n = s.length();
        std::vector<int> delta(n + 1, 0); 
        
      
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            delta[start] += value;
            if (end + 1 < n) delta[end + 1] -= value;
        }
        
      
        int net_shift = 0;
        for (int i = 0; i < n; ++i) {
            net_shift += delta[i];  
            int shift_amount = ((net_shift % 26) + 26) % 26; 
            s[i] = 'a' + (s[i] - 'a' + shift_amount) % 26;  
        }
        
        return s;
    }
};

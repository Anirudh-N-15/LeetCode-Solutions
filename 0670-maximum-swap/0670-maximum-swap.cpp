class Solution {
public:
    int maximumSwap(int num) {
        string numstring = to_string(num);
        int n = numstring.size();
        int maxIdx = n - 1;
        int x = -1, y = -1;  

        for (int i = n - 2; i >= 0; --i) {
            if (numstring[i] < numstring[maxIdx]) {
                x = i; 
                y = maxIdx; 
            }
            if (numstring[i] > numstring[maxIdx]) {
                maxIdx = i;
            }
        }

        if (x != -1 && y != -1) {
            swap(numstring[x], numstring[y]);
        }

        return stoi(numstring);
    }
};

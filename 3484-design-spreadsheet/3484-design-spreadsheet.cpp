class Spreadsheet {
public:
    unordered_map<string,int> umap ;
    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        umap[cell] = value ;
    }
    
    void resetCell(string cell) {
        umap[cell] = 0;
    }

    bool isInteger(const string& s) {
        if (s.empty()) return false;

        int start = 0;
        if (s[0] == '+' || s[0] == '-') {
            if (s.size() == 1) return false; // only '+' or '-' is not valid
            start = 1;
        }

        return all_of(s.begin() + start, s.end(), ::isdigit);
    }

    
    int getValue(string formula) {
        string temp = "" ;
        int val = 0;
    
        for (int i = 0; i < formula.size(); i++) {
            char ch = formula[i];
        
            if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                temp += ch;
            } else {
            
                if (!temp.empty()) {
                    if (umap.find(temp) != umap.end()) {
                        val += umap[temp];
                    } else if (isInteger(temp)) {
                        val += stoi(temp);
                    }
                    temp.clear();
                }
            }
        }
    
        if (!temp.empty()) {
            if (umap.find(temp) != umap.end()) {
                val += umap[temp];
            } else if (isInteger(temp)) {
                val += stoi(temp);
            }
        }
        return val;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
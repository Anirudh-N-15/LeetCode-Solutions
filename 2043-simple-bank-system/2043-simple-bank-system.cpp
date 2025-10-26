class Bank {
public:
    int n;
    vector<long long> numsBalance{100,0} ;
    Bank(vector<long long>& balance) {
        n = balance.size() ;
        numsBalance.resize(n+1);
        for(int i=1;i<=n;i++) {
            numsBalance[i] = balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if( (account1 < 1 || account1 > n)) {
            return false ;
        }
        if((account2 < 1 || account2 > n)) {
            return false ;
        }
        if(numsBalance[account1] < money) {
            return false ;
        }
        numsBalance[account1 ] -= money ;
        numsBalance[account2 ] += money ;
        return true ;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > n) {
            return false ;
        }
        numsBalance[account] += money ;
        return true ;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > n) {
            return false ;
        }
        if(numsBalance[account] < money) {
            return false ;
        }
        numsBalance[account] -= money ;
        return true ;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
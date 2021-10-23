class Bank {
public:
    vector<long long> balance;
    
    Bank(vector<long long>& balance) {
        balance.push_back(1e16+5);
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--, account2--;
        if(account1 >= balance.size() || account2 >= balance.size()) return false;
        
        if(balance[account1] >= money)
        {
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        }
        
        return false;
    }
    
    bool deposit(int account, long long money) {
        return transfer(balance.size(), account, money);
    }
    
    bool withdraw(int account, long long money) {
        return transfer(account, (int)balance.size(), money);
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

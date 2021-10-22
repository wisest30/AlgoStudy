class Bank {
public:
    vector<long long> A;
    Bank(vector<long long>& balance) {
        A = balance;
    }
    
    bool transfer(int i, int j, long long money) {
        --i, --j;
        if(i >= A.size() || j >= A.size() || A[i] < money) return false;
        A[i] -= money;
        A[j] += money;
        return true;
    }
    
    bool deposit(int i, long long money) {
        --i;
        if(i >= A.size()) return false;
        A[i] += money;
        return true;
    }
    
    bool withdraw(int i, long long money) {
        --i;
        if(i >= A.size() || A[i] < money) return false;
        A[i] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

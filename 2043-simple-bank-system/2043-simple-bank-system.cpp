class Bank {
public:
    vector<long long> bal;
    
    Bank(vector<long long>& balance) {
        bal.resize(balance.size());
        copy(balance.begin(), balance.end(), bal.begin());
    }
    
    bool transfer(int account1, int account2, long long money) {
        // Ensure both account1 and account2 are valid and the transfer amount is possible
        if(account1 < 1 || account1 > bal.size() || account2 < 1 || account2 > bal.size() || bal[account1-1] < money)
            return false;
        
        bal[account1-1] -= money;
        bal[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        // Ensure account is valid
        if(account < 1 || account > bal.size()) return false;
        
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        // Ensure account is valid
        if(account < 1 || account > bal.size()) return false;
        
        // Check if there is enough balance
        if(bal[account-1] >= money) {
            bal[account-1] -= money;
            return true;
        }
        return false;
    }
};

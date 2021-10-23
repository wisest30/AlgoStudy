let gBalance = [];

/**
 * @param {number[]} balance
 */
var Bank = function(balance) {
    gBalance = balance.slice();
};

/** 
 * @param {number} account1 
 * @param {number} account2 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function(account1, account2, money) {
    if (!Bank.prototype.isValidAccounts([account1, account2])) {
        return false;
    }
    
    if (Bank.prototype.withdraw(account1, money)) {
        return Bank.prototype.deposit(account2, money);
    }
    
    return false;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function(account, money) {    
    if (!Bank.prototype.isValidAccounts([account])) {
        return false;
    }
    
    gBalance[account - 1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function(account, money) {
    if (!Bank.prototype.isValidAccounts([account])) {
        return false;
    }
    if (gBalance[account - 1] < money) {
        return false;
    }
    
    gBalance[account - 1] -= money;
    return true;
};

/** 
 * @param {number[]} account 
 * @return {boolean}
 */
Bank.prototype.isValidAccounts = function(accounts) {
    for (let i = 0; i < accounts.length; i++) {
        const account = accounts[i];
        if (account < 1 || account > gBalance.length) {
            return false;
        }
    }
    return true;
};

/** 
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
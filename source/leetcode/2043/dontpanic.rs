/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank::new(balance);
 * let ret_1: bool = obj.transfer(account1, account2, money);
 * let ret_2: bool = obj.deposit(account, money);
 * let ret_3: bool = obj.withdraw(account, money);
 */
struct Bank {
    bal: Vec<i64>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {
    fn new(balance: Vec<i64>) -> Self {
        Bank { bal: balance }
    }

    fn transfer(&mut self, a1: i32, a2: i32, money: i64) -> bool {
        let i1 = (a1 - 1) as usize;
        let i2 = (a2 - 1) as usize;

        match self.bal.get(i1) {
            Some(_) => (),
            None => return false,
        }
        match self.bal.get(i2) {
            Some(_) => (),
            None => return false,
        }

        if self.bal[i1] >= money {
            self.bal[i1] -= money;
            self.bal[i2] += money;
            true
        } else {
            false
        }
    }

    fn deposit(&mut self, a: i32, money: i64) -> bool {
        let i = (a - 1) as usize;
        match self.bal.get_mut(i) {
            Some(bal) => {
                *bal += money;
                true
            }
            None => false,
        }
    }

    fn withdraw(&mut self, a: i32, money: i64) -> bool {
        let i = (a - 1) as usize;
        match self.bal.get_mut(i) {
            Some(bal) => {
                if *bal >= money {
                    *bal -= money;
                    true
                } else {
                    false
                }
            }
            None => false,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bank_typical() {
        //["Bank","withdraw","transfer","deposit","transfer","withdraw"]
        //[[[10,100,20,50,30]],[3,10],[5,1,20],[5,20],[3,4,15],[10,50]]
        let mut bank = Bank::new(vec![10, 100, 20, 50, 30]);
        assert_eq!(true, bank.withdraw(3, 10));
        assert_eq!(true, bank.transfer(5, 1, 20));
        assert_eq!(true, bank.deposit(5, 20));
        assert_eq!(false, bank.transfer(3, 4, 15));
        assert_eq!(false, bank.withdraw(10, 50));
    }
}

class ATM:
    def __init__(self):
        self.A = [0] * 5

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5) :
            self.A[i] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        P = [20, 50, 100, 200, 500]
        ret = [0] * 5
        for i in range(4, -1, -1) :
            p = P[i]
            ret[i] = min(amount // p, self.A[i])
            amount -= ret[i] * p
        
        if amount :
            return [-1]
        
        for i in range(5) :
            self.A[i] -= ret[i]
        
        return ret

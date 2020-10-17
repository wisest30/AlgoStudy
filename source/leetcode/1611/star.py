class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        self.binary = []
        while n:
            self.binary.append(n & 1)
            n //= 2
        self.dp = [1]
        m = len(self.binary)
        for i in range(1, m):
            self.dp.append(2*self.dp[i - 1] + 1)
        self.dp.append(0)
        return self.make(m - 1, 0)
    
    def make(self, pos, target):
        if pos < 0:
            return 0
        if self.binary[pos] != target:
            return self.make(pos - 1, 1) + self.dp[pos - 1] + 1
        else:
            return self.make(pos - 1, 0)
            
        
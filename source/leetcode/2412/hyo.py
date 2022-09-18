class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        s = sum(max(0, t[0] - t[1]) for t in transactions)
        return max(s + t[0] - max(0, t[0] - t[1]) for t in transactions)
class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        n = len(statements)
        def valid(subset) :
            def isGood(i) : return (subset & (1 << i)) > 0
            def valid_i(i) : return all(isGood(j) == statements[i][j] for j in range(n) if statements[i][j] != 2)
            return all(valid_i(i) for i in range(n) if isGood(i))

        return max(bin(subset).count('1') if valid(subset) else 0 for subset in range(1 << n))

class Solution:
    def countVowelStrings(self, n: int) -> int:
        cnt = [1] * 5
        for _ in range(1, n):
            cnt = [sum(cnt[i:]) for i in range(5)]
        return sum(cnt)

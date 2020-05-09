class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        if len(cardPoints) <= k:
            return sum(cardPoints)
        
        p = cardPoints[:k][::-1] + cardPoints[-k:][::-1]
        prefixSum = [p[0]]
        for n in p[1:]:
            prefixSum.append(n + prefixSum[-1])
        return max(prefixSum[i + k - 1] - (prefixSum[i - 1] if i > 0 else 0) for i in range(len(p) - k + 1))

class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        def score(bobArrows) :
            return 0 if not bobArrows else sum(i for i in range(12) if bobArrows[i] > aliceArrows[i])
        
        def adjust(bobArrows) :
            return [] if sum(bobArrows) > numArrows else [bobArrows[0] + numArrows - sum(bobArrows)] + bobArrows[1:]

        def from_subset(subset) :
            return adjust([aliceArrows[i] + 1 if (subset & 1 << i) else 0 for i in range(12)])
        
        return max([from_subset(subset) for subset in range(1 << 12)], key = lambda x : score(x))

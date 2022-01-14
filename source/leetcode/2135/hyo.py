class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        startSortedSet = set(["".join(sorted(s)) for s in startWords])
        targetSorted = [sorted(s) for s in targetWords]
        return sum([any(["".join(s[:i] + s[i+1:]) in startSortedSet for i in range(len(s))]) for s in targetSorted])

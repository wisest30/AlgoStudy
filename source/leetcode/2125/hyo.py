class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        A = [s.count("1") for s in bank if "1" in s]
        return sum([A[i] * A[i+1] for i in range(len(A) - 1)])

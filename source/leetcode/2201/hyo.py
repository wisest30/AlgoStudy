class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        s = set(tuple(d) for d in dig)
        return sum(all((y, x) in s for y in range(a[0], a[2] + 1) for x in range(a[1], a[3] + 1)) for a in artifacts)

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s, d = map(set, zip(*paths))
        return (d - s).pop()

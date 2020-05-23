class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        seen = set(target)
        array = [['Push'] if i in seen else ['Push', 'Pop']
                 for i in range(1, target[-1] + 1)]
        return sum(array, [])

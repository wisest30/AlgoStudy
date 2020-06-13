class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizon = [0] + sorted(horizontalCuts) + [h]
        vertical = [0] + sorted(verticalCuts) + [w]

        horizon = max(y - x for x, y in zip(horizon, horizon[1:]))
        vertical = max(y - x for x, y in zip(vertical, vertical[1:]))
        return (horizon * vertical) % (10 ** 9 + 7)

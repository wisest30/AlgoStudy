class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        heap = []
        ans = 0
        for idx in range(1, n):
            diff = heights[idx] - heights[idx - 1]
            if diff < 0:
                continue
            heappush(heap, diff)
            if len(heap) > ladders:
                bricks -= heappop(heap)
            if bricks < 0:
                return idx - 1
        return n - 1
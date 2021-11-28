class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        ret, c = 0, capacity
        for i, v in enumerate(plants) :
            ret += 1 if c >= v else 2 * i + 1
            c = c - v if c >= v else capacity - v
        
        return ret

# gradient 관련 참고 자료 - https://datascienceschool.net/view-notebook/4642b9f187784444b8f3a8309c583007/
import numpy as np
from scipy.optimize import minimize
class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        x0 = sum([x for x, y in positions]) / len(positions)
        y0 = sum([y for x, y in positions]) / len(positions)
        
        def getCost(pt):
            avgX, avgY = pt
            cost = 0
            for x, y in positions:
                cost += ((x - avgX) ** 2 + (y - avgY) ** 2) ** 0.5
            return cost
        res = minimize(getCost, [x0, y0])
        return res.fun

class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        import numpy as np
        return all([len(set(arr)) == len(arr) for arr in np.concatenate((matrix, np.array(matrix).T))])

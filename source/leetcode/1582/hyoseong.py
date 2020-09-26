import numpy as np
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        r = len(mat)
        c = len(mat[0])
        mat_t = np.transpose(mat)
        ret = 0
        for y in range(r) :
            for x in range(c) :
                if mat[y][x] == 1 and sum(mat[y]) == sum(mat_t[x]) == 1 :
                    ret += 1
        return ret

class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        def lis_len(A) :
            temp = []
            for x in A :
                p = bisect_right(temp, x)
                if p < len(temp) : temp[p] = x
                else : temp.append(x)
            return len(temp)
        
        ret = 0
        for i in range(k) :
            A = arr[i::k]
            ret += len(A) - lis_len(A)
        return ret

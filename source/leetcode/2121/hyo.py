class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        n = len(arr)
        A = defaultdict(list)
        for i in range(n) :
            A[arr[i]].append(i)
        
        ret = [0] * n
        for a in A.values() :
            rs = sum(a)
            rc = len(a)
            ls = 0
            lc = 0
            
            for i in range(len(a)) :
                rs -= a[i]
                rc -= 1
                
                ret[a[i]] = rs - a[i] * rc + a[i] * lc - ls 
                
                ls += a[i]
                lc += 1
        
        return ret

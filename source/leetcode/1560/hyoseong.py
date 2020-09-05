class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        A = [rounds[0]]
        for i in range(1, len(rounds)) :
            j = A[-1]
            while j != rounds[i] :
                j += 1
                if j > n :
                    j = 1
                A.append(j)
        
        C = Counter(A)
        max_val = -1
        for key in C :
            max_val = max(max_val, C[key])
        ret = []
        for key in C :
            if C[key] == max_val :
                ret.append(key)
        ret.sort()
        return ret

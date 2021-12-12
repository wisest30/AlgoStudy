class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        A = Counter(digits)
        ret = set()
        for i in A :
            for j in A :
                for k in A :
                    if i == 0 or k % 2 == 1:
                        continue

                    num = i * 100 + 10 * j + k
                    if i == j == k :
                        if A[i] >= 3 :
                            ret.add(num)
                    elif i == j or i == k :
                        if A[i] >= 2 :
                            ret.add(num)
                    elif j == k :
                        if A[j] >= 2 :
                            ret.add(num)
                    else :
                        ret.add(num)
        
        return sorted(ret)
                        
                            
            

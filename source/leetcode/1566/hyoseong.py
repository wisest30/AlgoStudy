class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        n = len(arr)
        for i in range(n) :
            if i + m > n :
                break
            for j in range(k) :
                if arr[i:i+m] != arr[i + m * j : i + m * (j+1)] :
                    break
            else :
                return True
        return False
            
                

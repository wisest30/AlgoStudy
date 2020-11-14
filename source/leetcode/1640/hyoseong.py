class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        try :
            pieces.sort(key = lambda x : arr.index(x[0]))
        except :
            return False
        
        ret = []
        for p in pieces :
            ret += p
        return ret == arr

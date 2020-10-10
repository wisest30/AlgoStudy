class Solution:
    def minOperations(self, logs: List[str]) -> int:
        L = []
        for log in logs :
            if log.startswith("../") :
                if L :
                    L.pop()
            elif log.startswith("./") :
                pass
            else :
                L.append(log[:-1])
        
        return len(L)

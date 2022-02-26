class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt, ret, repeat = Counter(s), [], 0
        while True :
            for c in reversed("abcdefghijklmnopqrstuvwxyz") :
                if not cnt[c] :
                    continue
                if ret and ret[-1] != c :
                        repeat = 0
                if repeat < repeatLimit :                    
                    repeat += 1
                    ret.append(c)
                    cnt[c] -= 1
                    break
            else :
                break
        
        return "".join(ret)
        

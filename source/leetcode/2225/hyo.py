class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        n = 10 ** 5 + 1
        win, lose = [0] * n, [0] * n
        for match in matches :
            win[match[0]] += 1
            lose[match[1]] += 1
        
        ret = [[], []]
        for i in range(len(win)) :
            if win[i] and not lose[i] :
                ret[0].append(i)
            elif lose[i] == 1 :
                ret[1].append(i)
        
        return ret

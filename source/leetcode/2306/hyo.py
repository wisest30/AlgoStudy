class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        s, ret, cnts = set(ideas), 0, [[0] * 26 for _ in range(26)]
        for idea in ideas :
            i = ord(idea[0]) - ord('a')
            for c in 'abcdefghijklmnopqrstuvwxyz' :
                j = ord(c) - ord('a')
                if c + idea[1:] not in s :
                    ret += cnts[j][i]
                    cnts[i][j] += 1
        ret *= 2
        return ret

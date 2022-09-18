class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        p, t, ret, i, j = sorted(players), sorted(trainers), 0, 0, 0
        for j in range(len(t)):
            if i >= len(p) : break
            if p[i] <= t[j] : ret, i = ret + 1, i + 1
        
        return ret
            
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        n = len(scores)
        g = [[] for i in range(n)]
        for e in edges :
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
        
        for i in range(n) :
            g[i].sort(key = lambda x : scores[x])
        
        ret = -1
        for e in edges :
            s = scores[e[0]] + scores[e[1]]
            candi = [[], []]
            for j in range(2) :
                for i in range(len(g[e[j]]) - 1, -1, -1) :
                    if len(candi[j]) >= 2 :
                        break

                    node = g[e[j]][i]
                    if node not in [e[0], e[1]] :
                        candi[j].append(node)
            
            if not candi[0] or not candi[1] :
                continue
            
            if candi[0][0] != candi[1][0] :
                s += scores[candi[0][0]] + scores[candi[1][0]]
            elif len(candi[0]) == 1 and len(candi[1]) >= 2:
                s += scores[candi[0][0]] + scores[candi[1][1]]
            elif len(candi[0]) >= 2 and len(candi[1]) == 1:
                s += scores[candi[0][1]] + scores[candi[1][0]]
            elif len(candi[0]) >= 2 and len(candi[1]) >= 2:
                s += scores[candi[0][0]] + max(scores[candi[0][1]], scores[candi[1][1]])
            else :
                continue
            
            ret = max(ret, s)
        
        return ret
            
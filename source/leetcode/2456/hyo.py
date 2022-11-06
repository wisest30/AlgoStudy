class Solution:
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        n = len(creators)
        D = dict()
        max_score = -1
        for i in range(n) :
            if creators[i] not in D :
                D[creators[i]] = [0, -1, ""]
            
            d = D[creators[i]]
            d[0] += views[i]
            if d[1] < views[i] or d[1] == views[i] and ids[i] < d[2]:
                d[1] = views[i]
                d[2] = ids[i]
            
            max_score = max(max_score, d[0])
        
        ret = []
        for key in D :
            if D[key][0] == max_score :
                ret.append([key, D[key][2]])
        
        return ret

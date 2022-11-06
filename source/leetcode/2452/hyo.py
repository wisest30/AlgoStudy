class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        def f(word1, word2) :
            return sum(1 for i in range(len(word1)) if word1[i] != word2[i])
        
        ret = []
        for q in queries :
            for d in dictionary :
                if f(q, d) <= 2 :
                    ret.append(q)
                    break
        
        return ret

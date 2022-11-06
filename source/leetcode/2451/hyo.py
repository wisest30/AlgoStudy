class Solution:
    def oddString(self, words: List[str]) -> str:
        def f(word) :
            return [ord(word[i+1]) - ord(word[i]) for i in range(len(word) - 1)]
        
        C = Counter([str(f(word)) for word in words])
        for p in C :
            if C[p] == 1 :
                for word in words :
                    if str(f(word)) == p :
                        return word

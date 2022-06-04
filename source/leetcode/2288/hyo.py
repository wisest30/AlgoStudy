class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        def isPrice(word) :
            if len(word) < 2 or word[0] != '$' :
                return False
            for i in range(1, len(word)) :
                if word[i] < '0' or word[i] > '9' :
                    return False
            return True
        
        def toDiscountPrice(word) :
            p = int(word[1:]) * (100 - discount) / 100
            return f'${p:.2f}'
        
        words = sentence.split()
        for i in range(len(words)) :
            if isPrice(words[i]) :
                words[i] = toDiscountPrice(words[i])
        
        return " ".join(words)

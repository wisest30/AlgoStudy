class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
       def count_chars(word):
           hmp = {}
           for c in word:
               if c not in hmp:
                   hmp[c] = 1
               else:
                   hmp[c] += 1
            return hmp

        hmp1, hmp2 = count_chars(word1), count_chars(word2)
        keys1, values1, keys2, values2 = hmp1.keys(), hmp1.values(), hmp2.keys(), hmp2.values()
        if keys1.sort() == keys.sort() and values1.sort() == values2.sort():
            return True
        return False

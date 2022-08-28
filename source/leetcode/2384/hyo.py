class Solution:
    def largestPalindromic(self, num: str) -> str:
        counter = Counter(num)
        left, mid = [], ""
        for num in "9876543210" :
            left.append(num * (counter[num] // 2))
            if not mid and counter[num] % 2 :
                mid = num
        
        ret = "".join(left) + mid + "".join(left[::-1])
        return ret if ret[0] != '0' else mid if mid else "0"

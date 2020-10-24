class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:        
        def isPalindrome(s) :
            for i in range(len(s)) :
                if s[i] != s[-i-1] :
                    return False
            return True
        
        n = len(a)
        def f(s, t) :
            x = 0
            while x < n and s[x] == t[-x-1] :
                x += 1
            return isPalindrome(s[:x] + t[x:]) or isPalindrome(s[:-x] + t[-x:])
        
        if f(a, b) or f(b, a) :
            return True
        else :
            return False
        

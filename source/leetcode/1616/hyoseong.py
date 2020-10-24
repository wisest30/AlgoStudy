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
            for i in range(n) :
                if s[i] == t[-i-1] :
                    x += 1
                else :
                    break
            if isPalindrome(s[:x] + t[x:]) :
                return True
            elif isPalindrome(s[:-x] + t[-x:]) :
                return True
            else :
                return False
        
        if f(a, b) or f(b, a) :
            return True
        else :
            return False
        

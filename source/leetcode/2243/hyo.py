class Solution:
    def digitSum(self, s: str, k: int) -> str:
        if len(s) <= k :
            return s
        
        def f(num_str) :
            return str(sum([int(d) for d in num_str]))
        
        return self.digitSum("".join([f(s[i:i+k]) for i in range(0, len(s), k)]), k)

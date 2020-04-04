class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            chk = set()
            for i in range(1, int(n ** 0.5)+1):
                tmp = n % i
                if tmp == 0:
                    if n//i in chk:
                        break
                    else:
                        chk.add(n//i)
                        chk.add(i)
            if len(chk) == 4:
                ans += sum(chk)
        return ans

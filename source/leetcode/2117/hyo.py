class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        A = list(range(left, right + 1))
        cnt = [0, 0]
        for i in range(len(A)) :
            while A[i] % 2 == 0 :
                cnt[0] += 1
                A[i] //= 2
            while A[i] % 5 == 0 :
                cnt[1] += 1
                A[i] //= 5

        c = min(cnt)
        cnt[0] -= c
        cnt[1] -= c

        if len(A) < 10000 :
            res = 2 ** cnt[0] * 5 ** cnt[1]
            for a in A :
                res *= a
            
            s = str(res)
            if len(s) <= 10 :
                return s + "e" + str(c)
            else :
                return s[:5] + "..." + s[-5:] + "e" + str(c)
        else :
            big = 10 ** 25
            pre = suf = 1
            for i in range(cnt[0]) :
                pre *= 2
                while pre > big :
                    pre //= 10
                suf = suf * 2 % 100000
            
            for i in range(cnt[1]) :
                pre *= 5
                while pre > big :
                    pre //= 10
                suf = suf * 5 % 100000
            
            for a in A :
                pre *= a
                while pre > big :
                    pre //= 10
                suf = suf * a % 100000
            
            pre = str(pre)[:5]
            suf = str(suf)
            while len(suf) < 5 :
                suf = "0" + suf

            return pre + "..." + suf + "e" + str(c)

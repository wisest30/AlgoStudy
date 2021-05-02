import sys
import bisect

limit = int(1e7)
db = []
def get(a, l):
    return int("".join(map(str,range(a, a+l))))
 


def solve():
    n = int(input())
    ans = int(1e20)
    for l in range(2, 19):
        left = 1
        right = int(1e10)
        # [left, right)
        while left < right:
            mid = (left+right)//2
            candid = get(mid, l)
            if candid > n and candid < ans:
                ans = candid
            if candid > n:
                right = mid
            else:
                left = mid + 1
    return ans


# print (db)
# print (len(db))
tc = int(input())
for i in range(1, tc+1):
    ans = solve()
    print ("Case #{}: {}".format(i, ans))

def minInteger(num: str, k: int) -> str:
    if k <= 0: return num
    n = len(num)
    if k >= n*(n-1)//2:
        return "".join(sorted(list(num)))

    for i in range(10):
        ind = num.find(str(i))
        if 0 <= ind <= k:
            return str(num[ind]) + minInteger(num[0:ind] + num[ind+1:], k-ind)

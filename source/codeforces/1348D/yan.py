def solve():
    res = []

    target = int(input()) - 1
    n = 1

    while n * 2 * 2 <= target:
        res.append(n)
        n *= 2
        target -= n

    if target <= n * 2:
        res.append(target - n)
    else:
        res.append(target // 2 - n)
        res.append(1 if target & 1 else 0)

    print(len(res))
    print(*res)


for _ in range(int(input())):
    solve()

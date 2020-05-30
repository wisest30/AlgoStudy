def msb(x):
    return len(bin(x)) - 2


def solve():
    d, mod = map(int, input().split())

    way = 1
    for i in range(msb(d) - 1):
        way += way * (1 << i)

    way += way * (d + 1 - (1 << (msb(d) - 1)))
    print((way - 1) % mod)



for _ in range(int(input())):
    solve()

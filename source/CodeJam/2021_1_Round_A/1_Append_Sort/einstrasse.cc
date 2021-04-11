import sys

def get(target, value):
    # return (minimum_append_len, value) for value  to overcome target.
    app_len = 0
    while (value <= target):
        if len(str(value)) == len(str(target)):
            app_len = app_len + 1
            value = value * 10
        else:
            diff = len(str(target)) - len(str(value))
            mini = maxi = value
            for i in range(diff):
                mini *= 10
                maxi *= 10
                maxi = maxi + 9
            if mini <= target and target < maxi:
                value = target + 1
            else:
                value = mini
            app_len = app_len + diff
    
    return (app_len, value)


def solve():
    n = int(input())
    arr = list(map(int, input().split(' ')))
    ans = 0
    for i in range(1, n):
        res = get(arr[i-1], arr[i])
        ans = ans + res[0]
        arr[i] = res[1]
    return ans

tc = int(input())
for i in range(1, tc+1):
    ans = solve()
    print ("Case #{}: {}".format(i, ans))

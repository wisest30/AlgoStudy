def maxArea(h: int, w: int, horizontal_cuts: List[int], vertical_cuts: List[int]) -> int:
    horizontal_cuts.sort()
    vertical_cuts.sort()

    prev = 0
    hor = 0
    for i in horizontal_cuts:
        hor = max(hor, i-prev)
        prev = i
    hor = max(hor, h-prev)

    prev = 0
    ver = 0
    for i in vertical_cuts:
        ver = max(ver, i-prev)
        prev = i
    ver = max(ver, w-prev)

    return (hor*ver)% 1000000007

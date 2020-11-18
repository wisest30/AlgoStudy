class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        def su(n, a, l) :
            return n * (a + l) // 2

        inventory.sort(reverse = True)
        inventory.append(0)
        ps = 0
        
        for i in range(len(inventory)) :
            if ps - inventory[i] * i >= orders :
                x = inventory[i-1]
                cnt = i
                break
            ps += inventory[i]
        
        ret = 0
        for i in range(cnt) :
            ret += su(inventory[i] - x, x + 1, inventory[i])
            orders -= inventory[i] - x
        n = orders // cnt

        ret += su(n, x - n + 1, x) * cnt
        ret += (x - n) * (orders % cnt)
        ret %= 10 ** 9 + 7
        return ret
        
                
        

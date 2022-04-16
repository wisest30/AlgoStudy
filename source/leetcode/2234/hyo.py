class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        flowers = [min(f, target) for f in flowers]
        n = len(flowers)
        flowers.sort()
        
        min_cost, target_cost = [0] * (n + 1), [0] * (n + 1)
        for i in range(n) :
            if flowers[i] < target :
                min_cost[i+1] = 0 if i == 0 else min_cost[i] + i * (flowers[i] - flowers[i-1])
            else :
                min_cost[i+1] = float('inf')
        
        target_cost[0] = target * n - sum(flowers)
        for i in range(n) :
            target_cost[i + 1] = target_cost[i] - (target - flowers[i])
        
        ret = 0
        for i in range(n+1) :
            if target_cost[i] > newFlowers :
                continue
            
            full_score = (n - i) * full
            remain = newFlowers - target_cost[i]

            if i == 0 :
                partial_score = 0
            else :
                j = bisect.bisect(min_cost, remain) - 1
                j = min(j, i)
                remain -= min_cost[j]
                partial_score = 0 if j == 0 else min(target - 1, flowers[j-1] + remain // j) * partial
            
            ret = max(ret, full_score + partial_score)

        return ret

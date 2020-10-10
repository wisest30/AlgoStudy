class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        cur = 0
        idx = -1
        max_val = 0
        profit = 0
        i = 0
        
        while i < len(customers) or cur > 0 :
            if i < len(customers) :
                cur += customers[i]
            x = min(4, cur)
            cur -= x

            profit += x * boardingCost - runningCost
            if profit > max_val :
                idx = i+1
                max_val = profit

            i += 1

        return idx

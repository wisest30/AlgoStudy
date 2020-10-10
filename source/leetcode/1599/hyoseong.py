class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        cur = 0
        A = [0]
        for i in range(len(customers)) :
            cur += customers[i]
            x = min(4, cur)
            cur -= x
            A.append(A[-1] + x * boardingCost - runningCost)
        while cur :
            x = min(4, cur)
            cur -= x
            A.append(A[-1] + x * boardingCost - runningCost)
        
        idx = -1
        max_val = 0
        for i in range(len(A)) :
            if A[i] > max_val :
                idx = i
                max_val = A[i]
        return idx

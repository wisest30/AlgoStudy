#TIME LIMIT
class Solution:
    #def 
    def maximumCandies(self, candies: List[int], k: int) -> int:

        len_candies=len(candies)
        max_num=0
        start=1
        end = sum(candies)//k
        for i in range(end):
            num_count=0
            for j in range(len(candies)):
                num_count+=candies[j]//(i+1)
            if num_count>=k:
                max_num=i+1
            if num_count<k:break
        return max_num
        

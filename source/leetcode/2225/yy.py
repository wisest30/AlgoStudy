class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        total_nums={}
        for match in matches:
            i,j=match
            if i not in total_nums:
                total_nums[i]=0
            if j not in total_nums:
                total_nums[j]=1
            else:total_nums[j]+=1
        sorted_dict = sorted(total_nums.items(), key = lambda item: item[0])
            
        result=[[],[]]
        for k,y in sorted_dict:
            if total_nums[k]==0:
                result[0].append(k)
            elif total_nums[k]==1:
                result[1].append(k)
       
        return result

## TIME LIMIT SOLUTION 
class Solution:
    def compute_gcd(self,x,y):
        while(y):
            x,y=y,x%y
        return x
    def compute_lcm(self,x,y):
        
        gcd=self.compute_gcd(x,y)
        if gcd==1 or y==1: return -1 
        lcm=x*y//gcd
        if x//gcd<1 or y //gcd<1:
            return -1
        return lcm
    
    def recur_replaceNonCoprimes(self,nums,prime_dict):
        
        origin_nums_len,idx,result_list=len(nums),0,[]
        while(idx < len(nums)-1):
            x,y=nums[idx],nums[idx+1]
            x_y="{}_{}".format(x,y)
            if  x_y in prime_dict:
                nums.pop(idx)
                nums[idx]=prime_dict[x_y]
                result_list.append(prime_dict[x_y])
            else:
                lcm=self.compute_lcm(x,y)
                if lcm==-1 or lcm==1:
                    idx+=1
                else:
                    nums.pop(idx)
                    nums[idx]=lcm
                    result_list.append(lcm)
                    prime_dict[x_y]=lcm                
        if len(nums)==origin_nums_len:
            return nums
        else:
            return self.recur_replaceNonCoprimes(nums,prime_dict)
        
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        result_list=[]
        idx=0
        nums=self.recur_replaceNonCoprimes(nums,{})
            
        
        return nums
        

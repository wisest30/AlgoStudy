class Solution {
public:
    int get_divisor_sum(int num)
    {
        int cnt = 0;
        int sum = 0;
        
        for(long long i=1;i*i<=num;++i)
        {
            if(num%i == 0)
            {
                if(i != num/i) 
                {
                    cnt += 2;
                    sum += i;
                    sum += num/i;
                }
                else 
                {
                    sum += i;
                    cnt++;
                }
            }
        }
        
        if(cnt == 4) return sum;
        return 0;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();++i)
        {
            ans += get_divisor_sum(nums[i]);
        }
        return ans;
    }
};

typedef long long ll;

class Solution {
public:
    int countDistinct(vector<int>& nums, int K, int p) {
        int n = nums.size();
        set<pair<int, int>> ansSet;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                bool valid = true;
                int cnt = 0;
                ll fir = 0;
                ll sec = 0;
                
                for(int k=i;k<=j;k++)
                {
                    if(nums[k]%p == 0) cnt++;
                    if(cnt > K)
                    {
                        valid = false;
                        break;
                    }
                    
                    fir = (fir * 211 + nums[k])%(1'000'000'007);
                    sec = (sec * 211 + nums[k])%(998'244'353);
                }
                
                if(valid) ansSet.insert({fir, sec});
            }
        }
        
        return ansSet.size();
    }
};

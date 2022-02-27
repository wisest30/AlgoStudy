class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<int> divisors;
        
        for(int i=1;1LL*i*i<=k;i++)
        {
            if(k%i == 0) divisors.push_back(i);
            if(k%i == 0 && i != k/i) divisors.push_back(k/i);
        }
        
        sort(divisors.begin(), divisors.end());
        
        unordered_map<int, int> divisorCnt;
        
        long long cnt = 0;
        
        for(int num : nums)
        {
            for(int i=divisors.size()-1;i>=0;--i)
            {
                if(num%divisors[i] == 0) 
                {
                    cnt += divisorCnt[k/divisors[i]];
                    break;
                }
            }
            
            for(int i=0;i<divisors.size();i++)
            {
                if(num%divisors[i] == 0) divisorCnt[divisors[i]]++;
            }
        }
        
        return cnt;
    }
};

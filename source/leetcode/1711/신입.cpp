class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9+7;
        map<int, int> cnt;
        
        long long ans = 0;
        
        for(int num : deliciousness)
        {
            for(int target=(1<<21);target>=1;target/=2)
            {
                int theOther = target-num;
                ans += cnt[theOther];
                ans %= MOD;
            }
            cnt[num]++;
        }
        
        return ans;
    }
};

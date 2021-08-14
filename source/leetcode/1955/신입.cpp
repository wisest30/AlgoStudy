class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int MOD = 1e9+7;
        
        int zeroFinish = 0;
        int oneFinish = 0;
        int twoFinish = 0;
        
        for(int num : nums)
        {
            if(num == 0) zeroFinish = ((zeroFinish + zeroFinish)%MOD + 1)%MOD;
            else if(num == 1 && zeroFinish) oneFinish = ((oneFinish + oneFinish)%MOD + zeroFinish)%MOD;
            else if(num == 2 && oneFinish) twoFinish = ((twoFinish + twoFinish)%MOD + oneFinish)%MOD;
        }
        
        return twoFinish;
    }
};

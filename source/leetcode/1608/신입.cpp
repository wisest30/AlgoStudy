class Solution {
public:
    int specialArray(vector<int>& nums) {
        int cnt[1000+5]{};
        
        for(int num : nums) cnt[num]++;
        for(int i=999;i>=0;--i) 
        {
            cnt[i] += cnt[i+1];
            if(cnt[i] == i) return i;
        }
        
        return -1;
    }
};

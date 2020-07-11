class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        auto cnt = vector<int>(k);
        for(auto a : arr) {
            if(a >= 0) cnt[a % k]++;
            else cnt[(a % k + k) % k]++;
        }
        if(cnt[0] % 2) return false;
        for(auto i = 1; i < k; ++i)
            if(cnt[i] != cnt[k-i]) return false;
        return true;
    }
};

class Solution {
    int range[200005];
    void set_range(int s, int e, int v) {
        if (s > e) return;
        range[s] += v;
        range[e+1] -= v;
    }
public:
    int minMoves(vector<int>& nums, int limit) {
        memset(range, 0, sizeof(range));
        for (int i=0; i < nums.size()/2; i++) {
            int a = nums[i];
            int b = nums[nums.size() - 1 - i];
            set_range(a+b+1, max(a,b)+limit, 1);
            set_range(min(a,b)+1, a+b-1, 1);
            set_range(2, min(a,b), 2);
            set_range(max(a,b)+limit+1, limit*2, 2);
        }
        for (int i=3; i <= limit*2; i++) {
            range[i] += range[i-1];
        }
        int ans = 987654321;
        for (int i=2; i<= limit*2; i++) {
            ans = min(ans, range[i]);
        }
        return ans;
    }
};

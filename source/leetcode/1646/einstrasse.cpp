class Solution {
public:
    int cache[105];
    int get(int idx) {
        int& ret = cache[idx];
        if (ret != -1) return ret;
        if (idx % 2 == 0)
            return ret = get(idx/2);
        else
            return ret = get(idx/2) + get(idx/2+1);
    }
    int getMaximumGenerated(int n) {
        
        memset(cache, -1, sizeof(cache));
        cache[0] = 0;
        cache[1] = 1;
        int ans = 0;
        for (int i=1; i <=n; i++) {
            ans = max(ans, get(i));
        }
        return ans;
    }
};

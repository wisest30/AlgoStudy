class Solution {
    // https://www.acmicpc.net/blog/view/21
    const int TREE_SIZE = 300005;
    const long long MOD = 1e9+7;
    long long tree[300005];
    long long get(int i) { // 0 ~ i까지의 합
        long long ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= (i & -i);
        }
        return ans;
    }
    void update(int i, long long diff) {
        while (i < TREE_SIZE) {
            tree[i] += diff;
            i += (i & -i);
        }
    }
public:
    int createSortedArray(vector<int>& instructions) {
        memset(tree, 0, sizeof(tree));
        long long ans = 0;
        for (int v : instructions) {
            ans += min(get(v-1), (get(100000) - get(v)));
            ans %= MOD;
            update(v, +1);
        }
        return ans;
    }
};

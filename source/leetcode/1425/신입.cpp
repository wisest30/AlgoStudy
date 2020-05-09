class Solution {
public:
    int segment_tree[400000];

    int init(int node, int s, int e)
    {
        if (s == e) return segment_tree[node] = -1000000000;
        return segment_tree[node] = max(init(node * 2, s, (s + e) / 2), init(node * 2 + 1, (s + e) / 2 + 1, e));
    }

    void update(int node, int s, int e, int idx, int diff)
    {
        if (idx > e) return;
        if (idx < s) return;
        if (s == e)
        {
            segment_tree[node] = diff;
            return;
        }
        update(node * 2, s, (s + e) / 2, idx, diff);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
        segment_tree[node] = max(segment_tree[2 * node], segment_tree[2 * node + 1]);
    }

    int get_mx(int node, int s, int e, int l, int r)
    {
        if (l <= s && e <= r) return segment_tree[node];
        if (l > e) return -1000000000;
        if (r < s) return -1000000000;

        int l_mx = get_mx(node * 2, s, (s + e) / 2, l, r);
        int r_mx = get_mx(node * 2 + 1, (s + e) / 2 + 1, e, l, r);

        return max(l_mx, r_mx);
    }

    int constrainedSubsetSum(vector<int> nums, int k) {
        init(1, 0, (int)nums.size() - 1);

        int ans = nums[0];
        update(1, 0, (int)nums.size() - 1, 0, nums[0]);

        for (int i = 1; i < nums.size(); ++i)
        {
            int temp = max(get_mx(1, 0, (int)nums.size() - 1, max(i - k, 0), i - 1), 0);
            update(1, 0, (int)nums.size() - 1, i, temp + nums[i]);
            if (temp + nums[i] > ans) ans = temp + nums[i];
        }

        return ans;
    }
};

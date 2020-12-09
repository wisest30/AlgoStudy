typedef pair<int, int> pii;
class Solution {
    pii tree[300000];
    pii init(int node, int start, int end, vector<int>& arr) {
        if (start + 1 == end) {
            return tree[node] = make_pair(arr[start], start);
        }
        int mid = (start+end)/2;
        pii left = init(node*2, start, mid, arr);
        pii right = init(node*2+1, mid, end, arr);
        if (left.first <= right.first) {
            return tree[node] = left;
        } else {
            return tree[node] = right;
        }
    }
    pii query(int node, int start, int end, int tstart, int tend) {
        if (tstart <= start && end <= tend) {
            return tree[node];
        }
        if (end <= tstart || tend <= start) {
            return make_pair(1e9+1, -1);
        }
        int mid = (start+end)/2;
        pii left = query(node*2, start, mid, tstart, tend);
        pii right = query(node*2+1, mid, end, tstart, tend);
        if (left.first <= right.first) return left;
        else return right;
    }
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        init(1, 0, nums.size(), nums);
        int s = 0;
        while (k--) {
            //printf("query(%d, %d)", s, nums.size() - k);
            pii t = query(1, 0, nums.size(), s, nums.size() - k);
            //printf(" = %d, %d\n", t.first, t.second);
            ans.push_back(t.first);
            s = t.second + 1;
        }
        return ans;
    }
};

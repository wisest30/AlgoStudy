#define MOD 1000000007
#define MAX_VAL 100000
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n): tree(n+1, 0) {
    }
    int sum(int n) {
        n++;
        int ret = 0;
        while (n != 0) {
            ret += tree[n];
            n -= (n&-n);
        }
        return ret;
    }
    void add(int n, int val) {
        n++;
        while (n < tree.size()) {
            tree[n] += val;
            n += (n & -n);
        }
    }
};
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int ret = 0;
        FenwickTree loTree(MAX_VAL), hiTree(MAX_VAL);
        for (int i=0; i<instructions.size(); i++) {
            int cur = instructions[i];
            int cost = min(loTree.sum(cur-1), hiTree.sum(getHiIdx(cur+1)));
            ret = (ret + cost)%MOD;
            loTree.add(cur, 1);
            hiTree.add(getHiIdx(cur), 1);
        }
        return ret;
    }
    int getHiIdx(int n) {
        return MAX_VAL+1-n;
    }
};
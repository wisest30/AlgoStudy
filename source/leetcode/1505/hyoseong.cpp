namespace {
    constexpr int MAX_N = 30000;
    long long T[MAX_N * 4 + 20], lazy[MAX_N * 4 + 20];
    bool tree_inited = false;
    void tree_init()
    {
        tree_inited = true;
        memset(T, 0, sizeof(T));
        memset(lazy, 0, sizeof(lazy));
    }
    void push(int i, int l, int r)
    {
        T[i] += lazy[i];
        if (l + 1 != r)
        {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    void pull(int i) {
        T[i] = T[i * 2 + 1] + T[i * 2 + 2];
    }
    void upd(int i, int l, int r, long long val, int L, int R)
    {
        if(!tree_inited) tree_init();
        push(i, l, r);
        if (r <= L || R <= l) return;
        if (L <= l && r <= R)
        {
            lazy[i] = val;
            push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        upd(i * 2 + 1, l, m, val, L, R);
        upd(i * 2 + 2, m, r, val, L, R);
        pull(i);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        if(!tree_inited) tree_init();
        push(i, l, r);
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = 0;
        if(L < m)
            ret += get(i * 2 + 1, l, m, L, R);
        if(R > m)
            ret += get(i * 2 + 2, m, r, L, R);

        return ret;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        auto A = vector<vector<int>>(10);
        for(auto i = 0; i < n; ++i) upd(0, 0, MAX_N, i, i, i+1);
        for(auto i = n-1; i >= 0; --i) A[num[i]-'0'].push_back(i);
        auto ret = string();
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < 10; ++j) {
                if(A[j].empty()) continue;
                auto idx = A[j].back();
                auto cost = get(0, 0, MAX_N, idx, idx+1);
                if(cost > k) continue;
                ret.push_back(num[idx]);
                k -= cost;
                A[j].pop_back();
                upd(0, 0, MAX_N, -1, idx+1, n);
                break;
            }
        }
        return ret;
    }
};

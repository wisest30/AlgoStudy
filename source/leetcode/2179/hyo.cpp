class FenwickTree {
public:
    int N;
    vector<long long> f;
    FenwickTree(int N) : N(N), f(vector<long long>(N+10)) {}
    void upd(int i, long long val) {
        assert(i >= 0 && i < N);
        for(; i < f.size(); i |= i+1) f[i] += val;
    }

    long long get(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f[i];
        return ret;
    }

    long long get(int l, int r) {
        assert(l >= 0 && l <= N);
        assert(r >= 0 && r <= N);
        return get(r) - get(l);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int, int> conv;
        for(auto i = 0; i < n; ++i) {
            conv[nums1[i]] = i;
        }
        
        long long ret = 0;
        FenwickTree ft_left(n), ft_right(n);
        for(auto i = 0; i < n; ++i)
            ft_right.upd(i, 1);

        for(auto num : nums2) {
            auto x = conv[num];
            auto left_cnt = ft_left.get(0, x);
            auto right_cnt = ft_right.get(0, n) - ft_right.get(0, x + 1);
            
            ret += left_cnt * right_cnt;
            
            ft_left.upd(x, 1);
            ft_right.upd(x, -1);
        }
        
        return ret;
    }
};

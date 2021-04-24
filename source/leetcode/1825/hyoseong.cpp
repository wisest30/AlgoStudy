namespace {
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
}

class MKAverage {
public:
    long long m, k;
    queue<long long> A;
    FenwickTree ft = FenwickTree{100001};
    FenwickTree ft2 = FenwickTree{100001};
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
    }
    
    void addElement(int num) {
        A.push(num);
        ft.upd(num, 1);
        ft2.upd(num, num);
        
        if(A.size() > m) {
            long long x = A.front();
            ft.upd(x, -1);
            ft2.upd(x, -x);
            A.pop();
        }
    }
    
    long long get_sum_nth(int n) {
        auto check = [&](long long mid) {
            auto cnt = ft.get(0, mid + 1);
            return cnt >= n;
        };
        
        long long l = 0, r = 100001;
        while(l + 1 < r) {
            auto mid = (l + r) / 2;
            if(check(mid))
                r = mid;
            else
                l = mid;
        }
        
        return ft2.get(r) + r * (n - ft.get(r));
    }
    
    int calculateMKAverage() {
        if(A.size() < m) return -1;
        
        auto x = get_sum_nth(m - k) - get_sum_nth(k);
        return x / (m - k - k);
    }
};

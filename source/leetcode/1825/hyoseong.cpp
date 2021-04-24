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
    vector<long long> A;
    FenwickTree ft = FenwickTree{100001};
    FenwickTree ft2 = FenwickTree{100001};
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
    }
    
    void addElement(int num) {
        A.push_back(num);
        ft.upd(num, 1);
        ft2.upd(num, num);
        
        if(A.size() > m) {
            long long x = A[(int)A.size() - m - 1];
            ft.upd(x, -1);
            ft2.upd(x, -x);
        }
    }
    
    int calculateMKAverage() {
        if(A.size() < m) return -1;
        
        auto check = [&](long long mm, int tp) {
            if(tp == 0) {
                auto x = ft.get(0, mm + 1);
                return x >= k;
            }
            else {
                auto x = ft.get(mm, 100001);
                return x >= k;
            }
        };

        long long ll = 0, rr = 0;

        long long l = 0, r = 100001;
        while(l + 1 < r) {
            auto mm = (l + r) / 2;
            if(check(mm, 0))
                r = mm;
            else
                l = mm;
        }
        ll = r;
        
        l = 0, r = 100001;
        while(l + 1 < r) {
            auto mm = (l + r) / 2;
            if(check(mm, 1))
                l = mm;
            else
                r = mm;
        }
        rr = l;

        if(ll == rr) {
            return ll;
        }

        long long x = 0;
        if(ll + 1 < rr)
            x = ft2.get(ll + 1, rr);

        long long d = ft.get(0, ll + 1) - k;
        x += ll * d;
        
        d = ft.get(rr, 100001) - k;
        x += rr * d;
        return x / (m - k - k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

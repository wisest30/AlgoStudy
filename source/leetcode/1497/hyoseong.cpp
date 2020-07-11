class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        auto A = vector<int>(k+1);
        long long s = 0;
        for(auto a : arr) {
            auto b = a;
            if(a < 0)
                b = a%k + k;            
            A[b % k]++;
            s+= b;
        }
        if(s % k) return false;
        auto n = (int)arr.size();
        if(n == 2 && A[0] != 2) return false;
        if(A[0]) return true;
        for(auto i = 1; i < k; ++i) {
            if(A[i] && A[k - i] && i != k-i) return true;
            else if(i == k-i && A[i] >= 2) return true;
        }
        return false;
    }
};

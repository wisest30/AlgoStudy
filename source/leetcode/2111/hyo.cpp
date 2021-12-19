class Solution {
public:
    template<typename T>
    int lis_len(const vector<T>& A) {
        auto L = vector<T>{};

        for(auto a : A) {
            auto p = upper_bound(L.begin(), L.end(), a) - L.begin();
            if(p == L.size()) L.push_back(a);
            else L[p] = a;
        }

        return L.size();
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int ret = 0;
        for(auto i = 0; i < k; ++i) {
            vector<int> A;
            for(auto j = i; j < arr.size(); j += k)
                A.push_back(arr[j]);
            
            auto len = lis_len(A);
            ret += (int)A.size() - len;
        }
        return ret;
    }
};

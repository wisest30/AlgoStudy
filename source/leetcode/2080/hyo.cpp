class RangeFreqQuery {
public:
    vector<vector<int>> idxs;
    RangeFreqQuery(vector<int>& arr) {
        idxs = vector<vector<int>>(10001);
        for(auto i = 0; i < arr.size(); ++i)
            idxs[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        auto& A = idxs[value];
        int ret = upper_bound(A.begin(), A.end(), right) - lower_bound(A.begin(), A.end(), left);
        return ret;
    }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n-1)/2];
        sort(arr.begin(), arr.end(), [&](const int& l, const int& r){
            return abs(l-m)==abs(r-m) ? l>r : abs(l-m) > abs(r-m);
        });
        vector<int> ret;
        for(int i=0; i<k; i++)
            ret.push_back(arr[i]);
        return ret;
    }
};

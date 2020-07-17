class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n<=2) return true;
        for(auto i = 2; i < n; ++i)
            if(arr[i] - arr[i-1] != arr[1] - arr[0]) return false;
        return true;
    }
};

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n);
        int ret = 0;
        for(int i=0; i<n; i++){
            arr[i] = start+2*i;
            ret ^= arr[i];
        }
        return ret;
    }
};

class Solution {
public:
    int minOperations(int n) {
        int k = (2*n-2+3)/4;
        int ret = (n-1-(k-1))*k;
        return ret;
    }
};

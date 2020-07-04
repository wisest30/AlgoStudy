class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for(int i = 0; i < n; i++){
            result ^= (start + i* 2);
        }
        return result;
    }
};

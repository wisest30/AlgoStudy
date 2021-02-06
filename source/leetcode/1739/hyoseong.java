class Solution {
    public int minimumBoxes(int n) {
        int ret = 0;
        for(int i = 1; n > 0; ++i)
            for(int j = 1; j <= i && n > 0; n -= j++)
                ret++;
        
        return ret;
    }
}

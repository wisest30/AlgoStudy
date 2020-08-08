class Solution {
public:
    int minFlips(string t) {
        int n = t.size();
        int ret = (t[0]=='1' ? 1 : 0);
        for(int i=1; i<n; i++){
            if(t[i]!=t[i-1]) ret++;
        }
        return ret;
    }
};

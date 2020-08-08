class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        target = "0" + target;
        
        for(int i=1;i<target.size();i++)
        {
            if(target[i] != target[i-1]) ans++;
        }
        
        return ans;
    }
};

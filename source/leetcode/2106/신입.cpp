typedef long long ll;

class Solution {
public:
    ll fenwick[4'00000+5];
    
    void upd(int idx, int diff)
    {
        for(;idx<=4'00000+1;idx += (idx&(-idx))) fenwick[idx] += diff;
    }
    
    ll get(int idx)
    {
        if(idx > 4'00001) idx = 4'00001;
        if(idx < 1) idx = 0;
        
        ll ret = 0;
        for(;idx;idx -= (idx&(-idx))) ret += fenwick[idx];
        return ret;
    }
    
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        for(auto &fruit : fruits) upd(fruit[0]+1, fruit[1]);
        startPos++;
        
        ll ans = 0;
        
        // left로 먼저 i칸, right로 나중에 k-i칸
        for(int i=0;i<=k;i++)
        {
            int st = max(startPos - i, 1);
            int ed = max(startPos - i + (k-i), startPos);
            
            ans = max(ans, get(ed) - get(st-1));
        }
        
        // right로 먼저 i칸, left로 나중에 k-i칸
        for(int i=0;i<=k;i++)
        {
            int st = min(startPos, startPos + i - (k-i));
            int ed = min(startPos + i, 4'00000+1);
            
            ans = max(ans, get(ed) - get(st-1));
        }
        
        return ans;
    }
};

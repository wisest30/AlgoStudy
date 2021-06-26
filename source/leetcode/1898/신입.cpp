class Solution {
public:
    bool isSubsequence(string s, string &p, vector<int>& removable, int use)
    {
        for(int i=0;i<use;i++) s[removable[i]] = '#';
        int sCur = 0;
        int pCur = 0;
     
        //if(use == 1) cout << s << "\n";
        
        while(sCur < s.size() && pCur < p.size())
        {
            //cout << s[sCur] << " " << p[pCur] << "\n";
            
            if(s[sCur] == p[pCur])
            {
                sCur++;
                pCur++;
            }
            else sCur++;
        }
        
        //if(use == 1) cout << pCur << "\n";
        
        return pCur == p.size();
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = (int)removable.size();
        int ans = 0;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            if(isSubsequence(s, p, removable, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        return ans;
    }
};

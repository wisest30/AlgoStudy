typedef long long ll;

class Solution {
public:
    ll mk(string base, int fromLen, int toLen)
    {
        if(base.empty()) return -1;
        
        string temp = base;
        if(toLen != 2*fromLen) temp = base.substr(0, (int)base.size()-1);
        
        reverse(temp.begin(), temp.end());
        
        string target = base + temp;
        
        ll res = 0;
        
        for(char ch : target) res = res * 10LL + ch - '0';
        
        return res;
    }
    
    ll mkPalindrome(int query, int fromLen, int toLen)
    {
        int st = 1;
        
        for(int i=0;i<fromLen-1;i++) st = st * 10;
        
        int target = st + query - 1;
        
        if(to_string(target).size() != fromLen) return mk("", 0, 0);
        return mk(to_string(target), fromLen, toLen);
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> ans;
        
        for(int query : queries) ans.push_back(mkPalindrome(query, (intLength+1)/2, intLength)); 
        return ans;
    }
};

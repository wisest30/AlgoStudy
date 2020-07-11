class Solution {
public:
    int numSubseq(vector<int>& ns, int t) {
        int MOD = 1e9+7;
        int twos[ns.size()+1];
        twos[0] = 1;
        for(int i=1; i<ns.size()+1; i++) twos[i] = twos[i-1]*2%MOD;
        
        sort(ns.begin(), ns.end());
        int ret = 0;
        for(int i=0; i<ns.size(); i++){
            int miny = ns[i];
            auto it = upper_bound(ns.begin()+i, ns.end(), t-miny);
            if(it==ns.begin()+i) break;
            int j = it-ns.begin();
            ret = (ret+twos[j-i-1]%MOD)%MOD;
            
        }
        return ret;
    }
};

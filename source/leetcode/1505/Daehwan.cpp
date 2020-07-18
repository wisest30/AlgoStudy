class Solution {
private:
    int fen[30001];
    void init(){
        memset(fen,0,sizeof(fen));
    }
    void add(int ix, int val){
        ix++;
        for(int i=ix; i<=30000; i+=(i&-i)) //parent
            fen[i] += val;
    }
    int query(int ix){
        ix++;
        int ret = 0;
        for(int i=ix; i>0; i-=(i&-i))
            ret += fen[i];
        return ret;
    }
public:
    string minInteger(string s, int k) {
        init();
        int n = s.size();
        queue<int> d2i[10];
        for(int i=0; i<n; i++){
            d2i[s[i]-'0'].push(i);
        }
        string ret="";
        set<int> iset;
        for(int l=0; l<n && k>0; l++){
            for(int d=0; d<10; d++){
                if(d2i[d].empty()) continue;
                int ix = d2i[d].front();
                int cost = ix - query(ix);
                if(k<cost) continue;
                k -= cost; add(ix,1); d2i[d].pop();
                ret += (d+'0'); iset.insert(ix);
                break;
            }
        }
        for(int ix=0; ix<n; ix++)
            if(!iset.count(ix)) ret += s[ix];
        return ret;
    }
};

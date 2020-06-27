class Solution {
public:
    int minDays(vector<int>& bs, int m, int k) {
        if(m*k > bs.size()) return -1;
        
        auto check = [&](int x)->bool{
            int bq = 0;
            int cs = 0;
            for(auto& b : bs){
                if(b<=x){
                    cs++;
                    if(cs==k){bq++; cs=0;} 
                }else{
                    cs=0;
                }
            }
            return bq>=m;
        };
        
        
        int f = 0;
        int t = 1e9;
        while(f+1<t){
            int m = (f+t)/2;
            if(check(m)) t = m;
            else f = m;
        }
        return t;
    }
};

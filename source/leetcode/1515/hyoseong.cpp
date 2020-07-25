class Solution {
public:
    double getMinDistSum(vector<vector<int>>& P) {
        int n = P.size();
        double x = 0, y = 0;
        
        auto f = [&](double m, int type) {
            double ret = 0;
            for(auto& p : P)
                if(type==0) ret += sqrt((x - p[0])*(x - p[0]) + (m - p[1])*(m - p[1]));
                else ret += sqrt((m - p[0])*(m - p[0]) + (y - p[1])*(y - p[1]));
            return ret;
        };

        for(auto i = 0; i < 100; ++i) {
            double l = 0, r = 100;
            int cnt = 100;
            while(cnt--) {
                double m1 = (2*l + r) / 3, m2 = (l + 2*r) / 3;
                if(f(m1, 0) < f(m2, 0)) r = m2;
                else l = m1;
            }
            y = l;

            l = 0, r = 100;
            cnt = 100;
            while(cnt--) {
                double m1 = (2*l + r) / 3, m2 = (l + 2*r) / 3;
                if(f(m1, 1) < f(m2, 1)) r = m2;
                else l = m1;
            }
            x = l;
        }
        
        double ret = 0;
        for(auto& p : P) ret += sqrt((x - p[0])*(x - p[0]) + (y - p[1])*(y - p[1]));
        return ret;
    }
};

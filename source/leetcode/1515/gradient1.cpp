struct point{
    double x;
    double y;
};


class Solution {
public:
    
    double sqr(double v)
    {
        return v*v;
    }
    
    double check(point& c, vector<point>& p)
    {
        double dist = 0;
        
        for(auto i:p)
        {
            dist += sqrt(sqr(i.x - c.x) + sqr(i.y - c.y));
        }
        
        return dist;
    }
    double getMinDistSum(vector<vector<int>>& p) {
    
        int n = p.size();
        
        vector<point> a(n);
        
        for(int i=0;i<n;++i)
            a[i] = {1.0*p[i][0], 1.0*p[i][1]};
        
        point c = {0,0};
        
        for(auto& i:p)
        {
            c.x+= i[0],
            c.y+= i[1];
        }
        
        c.x/=n,
        c.y/=n;
        
        for(double d = 50; d> 1e-6; )
        {
            bool found = false;
            point e = {c.x + d, c.y};
            if(check(e,a) < check(c,a))
                c=e, found =1;
            e = {c.x-d,c.y};
            if(check(e,a) < check(c,a))
                c=e, found =1;
            e= {c.x, c.y+d};
            if(check(e,a) < check(c,a))
                c=e, found =1;
            e = {c.x, c.y-d};
            if(check(e,a) < check(c,a))
                c=e, found =1;
            if(!found)
                d/=2;
        }
        
        return check(c,a);
    }
};

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<long double> angles;
        const long double pi = M_PIl;
        int add = 0;
        
        for(auto &thisPoint : points)
        {
            long double x = thisPoint[0] - location[0];
            long double y = thisPoint[1] - location[1];
            
            if(x == 0 && y == 0)
            {
                add++;
                continue;
            }
            
            long double thisAngle = acosl(x/sqrtl(x*x+y*y));
            if(y < 0) thisAngle = 2*pi - thisAngle;
            
            angles.push_back(thisAngle);
        }
        
        sort(angles.begin(), angles.end());
        
        long double range = (long double)angle/180*pi;
        
        int l=0;
        int ans = 0;
        int cnt = 0;
        
        //for(auto &out : angles) cout << cnt++ << " " << out << "\n";
        //cout << "range : " << range << "\n";
        //cout << "add : " << add << "\n";
        
        for(int r=0;r<2*angles.size();r++)
        {
            while(true)
            {
                long double diff = angles[r%angles.size()] - angles[l%angles.size()];
                if(diff < 0) diff += 2*pi;
                
                if(diff > range) l++;
                else if(r-l+1 > angles.size()) l++;
                else break;
            }
            if(r-l+1 > ans) ans = r-l+1;    
        }
        
        return ans + add;
    }
};

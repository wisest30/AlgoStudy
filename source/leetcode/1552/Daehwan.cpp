class Solution {
public:
    
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        auto check = [&](int d)->bool{
            int cnt = 1;
            int previ = 0;
            for(int i=1; i<p.size(); i++){
                if(p[i]-p[previ]>=d){cnt++;previ=i;}
            }
            if(cnt>=m) return true;
            else return false;
        }; 
        int l = 1; //true
        int r = 1e9; //false;
        while(l+1<r){
            int mid = (l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        return l;
    }
};

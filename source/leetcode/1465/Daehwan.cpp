class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        vector<int> diff1, diff2;
        int p = 0;
        for(int i=0; i<hc.size(); i++){
            diff1.push_back(hc[i]-p);
            p = hc[i];
        }diff1.push_back(h-p);
        p = 0;
        for(int i=0; i<vc.size(); i++){
            diff2.push_back(vc[i]-p);
            p = vc[i];
        }diff2.push_back(w-p);
        long long max1 = *(max_element(diff1.begin(), diff1.end()));
        long long max2 = *(max_element(diff2.begin(), diff2.end()));
        int mod = (int)(1e9+7);
        return (max1%mod)*(max2%mod)%mod;
    }
};

#include <algorithm>
using namespace std;
class Solution {
private:
    typedef long long LL;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        LL max_width = 0;
        LL max_height = 0;
        LL mod = 1000000007;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i = 0; i + 1< horizontalCuts.size(); i++){
            max_height = max(max_height, (LL)(horizontalCuts[i+1] - horizontalCuts[i]));
        }
        for(int i = 0; i + 1< verticalCuts.size(); i++){
            max_width = max(max_width, (LL)(verticalCuts[i+1] - verticalCuts[i]));
        }
        return (max_width * max_height) % mod;
    }
};

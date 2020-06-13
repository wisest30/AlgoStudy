class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHorizontal = 0;
        
        for(int i=0;i+1<horizontalCuts.size();++i)
        {
            int val = horizontalCuts[i+1] - horizontalCuts[i];
            if(val > maxHorizontal) maxHorizontal = val;
        }
        
        int maxVertical = 0;
        
        for(int i=0;i+1<verticalCuts.size();++i)
        {
            int val = verticalCuts[i+1] - verticalCuts[i];
            if(val > maxVertical) maxVertical = val;
        }
        
        return (1LL*maxHorizontal*maxVertical)%(1'000'000'007);
    }
};

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        map<int, vector<int>> yToX;
        
        for(auto &rectangle : rectangles) yToX[rectangle[1]].push_back(rectangle[0]);
        
        for(auto it = yToX.begin();it != yToX.end();it++) sort(it->second.begin(), it->second.end());
        
        vector<int> ans;
        
        for(auto &point : points)
        {
            int thisAns = 0;
            
            for(int i=point[1];i<=100;i++) thisAns += yToX[i].end() - lower_bound(yToX[i].begin(), yToX[i].end(), point[0]);    
            ans.push_back(thisAns);
        }
        
        return ans;
    }
};

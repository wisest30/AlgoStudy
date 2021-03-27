class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<array<double, 3>> q;
        for(auto& c : classes)
            q.push({(double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1], (double)c[0], (double)c[1]});
        
        for(auto i = 0; i < extraStudents; ++i) {
            auto c = q.top();
            q.pop();
            q.push({(double)(c[1] + 2) / (c[2] + 2) - (double)(c[1] + 1)/ (c[2] + 1), c[1] + 1, c[2] + 1});
        }
        
        double ret = 0;
        while(!q.empty()) {
            ret += q.top()[1] / q.top()[2];
            q.pop();
        }
        
        ret /= classes.size();
        return ret;
    }
};

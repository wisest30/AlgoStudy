class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> A, ret;
        for(auto i = 0; i < n; ++i) {
            auto p = upper_bound(A.begin(), A.end(), obstacles[i]) - A.begin();
            
            if(p == A.size())
                A.push_back(obstacles[i]);
            else
                A[p] = obstacles[i];
            
            ret.push_back(p+1);
        }
        
        return ret;
    }
};

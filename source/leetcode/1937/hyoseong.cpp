class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size(), c = points[0].size();
        auto A = vector<vector<long long>>(r, vector<long long>(c));
        for(auto i = 0; i < r; ++i)
            for(auto j = 0; j < c; ++j)
                A[i][j] = points[i][j];
        
        priority_queue<array<long long, 2>> right, left;
        auto clear_queue = [&]() {
            while(!right.empty()) right.pop();
            while(!left.empty()) left.pop();
        };
        
        for(auto i = 0; i < r; ++i) {
            if(i > 0) {
                for(auto j = 0; j < c; ++j) {
                    while(right.top()[1] < j) right.pop();              
                    auto k = right.top()[1];

                    long long candi0 = A[i-1][k] - abs(j-k);
                    long long candi1 = 0;
                    if(j > 0) {
                        auto k = left.top()[1];
                        candi1 = max(0ll, A[i-1][k] - abs(j-k));
                    }

                    A[i][j] += max(candi0, candi1);

                    left.push({A[i-1][j] + j, j});
                }
            }
            
            clear_queue();
            for(auto j = 0; j < c; ++j)
                right.push({A[i][j] - j, j});
        }
        
        auto ret = *max_element(A.back().begin(), A.back().end());
        return ret;
    }
};

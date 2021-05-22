class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> A(3000);
        for(auto& log : logs)
            for(auto i = log[0]; i < log[1]; ++i)
                A[i]++;
        
        auto ret = max_element(A.begin(), A.end()) - A.begin();
        return ret;
    }
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        
        vector<int> ret(n);
        
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < n; ++j)
                if(boxes[j] == '1')
                    ret[i] += abs(i - j);
        
        return ret;
    }
};

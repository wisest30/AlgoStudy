class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream is(s);
        string t;
        vector<int> A;
        
        while(is >> t)
            if(t[0] >= '0' && t[0] <= '9')
                A.push_back(stoi(t));
        
        for(auto i = 0; i < (int)A.size() - 1; ++i)
            if(A[i] >= A[i+1]) return false;
        
        return true;
    }
};

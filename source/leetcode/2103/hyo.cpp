class Solution {
public:
    int countPoints(string rings) {
        int A[10] = {};
        for(auto i = 0; i < rings.size(); i += 2)
            A[rings[i+1] - '0'] |= 1 << string("RGB").find(rings.substr(i, 1));
        
        return count(A, A + 10, 0b111);
    }
};

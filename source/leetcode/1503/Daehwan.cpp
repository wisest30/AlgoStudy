class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int r = 0; int l = 0;
        if(right.size()) r = n-*min_element(right.begin(), right.end());
        if(left.size()) l = *max_element(left.begin(), left.end());
        return max(r,l);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& n) {
        sort(n.begin(),n.end());
        return (*(n.end()-1)-1)*(*(n.end()-2)-1);
    }
};

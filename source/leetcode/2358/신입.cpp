class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i, sum;
        
        for(i=1, sum=0;sum+i<=n;i++) sum += i;
        return i-1;
    }
};

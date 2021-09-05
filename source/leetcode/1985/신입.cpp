class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(),
            [&](const string &a, const string &b)
             {
                 if(a.size() != b.size()) return a.size() > b.size();
                 for(int i=0;i<a.size();i++)
                 {
                     if(a[i] != b[i]) return a[i] > b[i];
                 }
                 return false;
             });
        
        return nums[k-1];
    }
};

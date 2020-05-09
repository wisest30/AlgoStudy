class Element {
    public :
        int r;
        int c;
};

bool operator<(const Element &a, const Element &b)
{
    if(a.r + a.c != b.r + b.c) return a.r + a.c < b.r + b.c;
    return a.r > b.r;
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<Element> elements;
        int mx_target = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums[i].size();++j)
            {
                elements.push_back({i, j});
            }
        }
        
        sort(elements.begin(), elements.end());
        
        for(int i=0;i<elements.size();++i) ans.push_back(nums[elements[i].r][elements[i].c]);
        
        return ans;
    }
};

typedef long long ll;

class Solution {
public:
    struct Element
    {
        int num;
        ll cost;
        
        bool operator<(const Element &rhs)
        {
            return this->num < rhs.num;
        }
    };
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll totalCost[1'000000+5]{};
        vector<Element> elements;
        
        for(int i=0;i<nums.size();i++) totalCost[nums[i]] += cost[i];
        
        ll costSum = 0;
        
        for(int i=1;i<=1'000000;i++)
        {
            if(totalCost[i]) elements.push_back({i, totalCost[i]});
            costSum -= totalCost[i];
        }
        
        int target = elements.back().num;
        int before = 1;
        
        for(auto& element : elements)
        {
            //printf("%d %d %d\n", element.num, element.cost, costSum);
            if(costSum >= 0)
            {
                target = before;
                break;
            }
            costSum += 2 * element.cost;
            before = element.num;
        }
        
        ll ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans += 1LL * abs(nums[i] - target) * cost[i];
        }
        
        return ans;
    }
};

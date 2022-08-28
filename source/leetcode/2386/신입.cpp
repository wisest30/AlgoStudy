typedef long long ll;

struct Element
{
    ll val;
    int idx;
};

bool operator<(const Element &a, const Element &b)
{
    return a.val > b.val;
}

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        ll tot = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] >= 0) tot += nums[i];
            else nums[i] = -nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        vector<ll> vec;
        vec.push_back(tot);
        
        priority_queue<Element> pq;
        pq.push({nums[0], 0});
        
        while(!pq.empty() && vec.size() < k)
        {
            Element cur = pq.top();
            pq.pop();
            
            vec.push_back(tot - cur.val);
            
            if(cur.idx+1 < n)
            {
                pq.push({cur.val + nums[cur.idx+1], cur.idx+1});
                pq.push({cur.val - nums[cur.idx] + nums[cur.idx+1], cur.idx+1});
            }
        }
        
        //for(int num : vec) cout << num << "\n";
        
        return vec.back();
    }
};

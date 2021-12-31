typedef long long ll;

class Solution {
public:
    struct Element
    {
        int cnt;
        ll sum;
    };
    
    unordered_map<int, Element> elementMap;
    
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> ans(n);
        
        for(int i=0;i<n;i++)
        {
            if(elementMap.count(arr[i])) ans[i] += 1LL * elementMap[arr[i]].cnt * i - elementMap[arr[i]].sum;
            elementMap[arr[i]].cnt++;
            elementMap[arr[i]].sum += i;
        }
        
        elementMap.clear();
        
        for(int i=n-1;i>=0;--i)
        {
            if(elementMap.count(arr[i])) ans[i] += elementMap[arr[i]].sum - 1LL * elementMap[arr[i]].cnt * i;
            elementMap[arr[i]].cnt++;
            elementMap[arr[i]].sum += i;
        }
        
        return ans;
    }
};

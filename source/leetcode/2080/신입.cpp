struct Element
{
    int val;
    int idx;
};

bool operator<(const Element &a, const Element &b)
{
    if(a.val != b.val) return a.val < b.val;
    return a.idx < b.idx;
}

class RangeFreqQuery {
public:
    vector<Element> elements;
    
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) elements.push_back({arr[i], i});
        sort(elements.begin(), elements.end());
    }
    
    int query(int left, int right, int value) {
        Element upperTemp = {value, right};
        auto r = upper_bound(elements.begin(), elements.end(), upperTemp);
        
        Element lowerTemp = {value, left};
        auto l = lower_bound(elements.begin(), elements.end(), lowerTemp);
        
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

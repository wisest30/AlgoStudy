using ll = long long;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        ll total = 0;
        ll largest = 0;
        for (ll m : milestones) {
            total += m;
            largest = max(largest, m);
        }
        ll a = largest;
        ll b = total - largest;
        ll ans;
        if (a > b) {
            ans = min(a, b) * 2;
            if (a != b) ans++;
        } else {
            ans = total;
        }
        return ans;
    }
};

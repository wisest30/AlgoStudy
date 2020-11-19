#define MOD 1000000007
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        int lo = 0, hi = 1000000000;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (satisfy(inventory, orders, mid)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int to = lo;
        int ret = 0;
        for (int i=0; i<inventory.size(); i++) {
            orders -= max(inventory[i] - to, 0);
            ret = ((long long int)ret+getSum(to+1, inventory[i])) % MOD;
        }
        ret = ((long long int)ret + (long long int)orders * to) % MOD;
        return ret;
    }
    // 모든 i에 대해 inventory[i]<=upper가 되게 만들 수 있는지 여부를 리턴.
    // satisfy하는 최소 upper값을 구하고 모든 inventory를 upper로 만든다. (단, 오름차순으로)
    bool satisfy(vector<int>& inventory, int orders, int upper) {
        for (int i=0; i<inventory.size(); i++) {
            int amount = max(inventory[i]-upper, 0);
            orders -= amount;
            if (orders < 0)
                return false;
        }
        return true;
    }
    int getSum(int start, int end) {
        if (end < start)
            return 0;
        return ((long long int)(start+end) * (end-start+1)/2) % MOD;
    }
};
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
typedef long long ll;
 
ll mx[200000+5];
ll mn[200000+5];
ll n, m, k, q;
 
vector<ll> valid_r;
 
ll safe_columns[200000+5];
ll dp[200000+5][2];
 
ll get_dist(ll lo, ll hi)
{
	if(lo > hi) swap(lo, hi);
 
	ll left = 500000;
	ll center = 500000;
	ll right = 500000;
 
	int left_idx = upper_bound(safe_columns, safe_columns+q, lo) - safe_columns;
	if(left_idx) left = lo - safe_columns[left_idx - 1] + hi - safe_columns[left_idx - 1];
	
	int center_idx = lower_bound(safe_columns, safe_columns+q, lo) - safe_columns;
	if(center_idx < q && safe_columns[center_idx] <= hi) center = hi - lo;
 
	int right_idx = lower_bound(safe_columns, safe_columns+q, hi) - safe_columns;
	if(right_idx < q) right = safe_columns[right_idx] - lo + safe_columns[right_idx] - hi;
	
	//printf("%lld %lld %lld %lld %lld\n", lo, hi, left, center, right);
 
	return min({left, center, right});
}
 
int main()
{
	memset(mn, 0x7f, sizeof(mn));
	valid_r.push_back(1);
 
	scanf("%lld %lld %lld %lld", &n, &m, &k, &q);
	
	for(int i=0;i<k;++i)
	{
		ll r, c;
		
		scanf("%lld %lld", &r, &c);
		
		valid_r.push_back(r);
 
		if(c > mx[r]) mx[r] = c;
		if(c < mn[r]) mn[r] = c;
	}
	
	for(int i=0;i<q;++i) scanf("%lld", &safe_columns[i]);
	sort(safe_columns, safe_columns + q);
	
	sort(valid_r.begin(), valid_r.end());
	valid_r.erase(unique(valid_r.begin(),valid_r.end()), valid_r.end());
 
	if(mx[1] == 0) 
	{
		dp[0][0] = dp[0][1] = 0;
		mx[1] = 1;
		mn[1] = 1;
	}
	else
	{
		dp[0][1] = mx[1] - 1;
		dp[0][0] = (mx[1] - 1) + (mx[1] - mn[1]);
	}
 
	for(int i=1;i<valid_r.size();++i)
	{
		dp[i][0] = valid_r[i] - valid_r[i-1] + dp[i-1][0] + mx[valid_r[i]] - mn[valid_r[i]] + get_dist(mn[valid_r[i-1]], mx[valid_r[i]]);
		ll temp = valid_r[i] - valid_r[i-1] + dp[i-1][1] + mx[valid_r[i]] - mn[valid_r[i]] + get_dist(mx[valid_r[i-1]], mx[valid_r[i]]);
		if(temp < dp[i][0]) dp[i][0] = temp;
		
		dp[i][1] = valid_r[i] - valid_r[i-1] + dp[i-1][0] + mx[valid_r[i]] - mn[valid_r[i]] + get_dist(mn[valid_r[i-1]], mn[valid_r[i]]);
		temp = valid_r[i] - valid_r[i-1] + dp[i-1][1] + mx[valid_r[i]] - mn[valid_r[i]] + get_dist(mx[valid_r[i-1]], mn[valid_r[i]]);
		if(temp < dp[i][1]) dp[i][1] = temp;
	}
 
	printf("%lld\n", min(dp[(int)valid_r.size()-1][0], dp[(int)valid_r.size()-1][1]));
 
	return 0;
}

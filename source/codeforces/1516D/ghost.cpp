#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;
typedef long long ll;
int n, q;
int a[100000];
int jmp[100001];
vector<int> v[100000];
int vIndex[100000];
int vStart[100000];

int notPrime[100001];
vector<int> factor[100000];
vector<int> primes;

int gcd(int a, int b) {
	
	int n;
	if (a < b) n = a, a = b, b = n;
	while (b)
		n = a%b, a = b, b = n;
	return a;
}


map<int, int> mii;

int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 0 ;i < n; i++)
		scanf("%d", a+i);
	
	for (int i = 2; i <= 100000; i++) {
		if (notPrime[i]) continue;
		primes.push_back(i);
		for (int j = i; j <= 100000; j += i)
			notPrime[j] = 1;
	}

	for (int i = 0; i < n; i++) {
		int t = a[i];
		for (auto& p : primes)
		{
			if (t < p)	break;
			if (t % p == 0)
			{
				factor[i].push_back(p);
				t /= p;
			}
		}
	}

	int l = 0, r = 0;
	while(r < n) {
		int goRight = 1;
		if (l < r)
		{
			for (auto& f : factor[r])
			{
				if (mii[f] != 0)
				{
					goRight = 0;
					break;
				}
			}
		}
		

		if (goRight)
		{
			for (auto& f : factor[r])
				mii[f]++;
			r++;
		}
		else
		{
			for (auto& f : factor[l])
				mii[f]--;
			jmp[l++] = r;
		}
	}
	while(l < r)
		jmp[l++] = r;



	for (int i = 0; i < n; i++)
		vIndex[i] = -1;

	for (int i = 0; i < n; i++)
	{
		if (~vIndex[i])	continue;
		
		for (int j = i; j < n; j = jmp[j])
		{
			vIndex[j] = i;
			vStart[j] = v[i].size();
			v[i].push_back(j);
		}
		v[i].push_back(n);
	}


	for (int qc = 0; qc < q; qc++)
	{
		int lq, rq;
		scanf("%d %d", &lq, &rq);
		lq--, rq--;
		vector<int>& vt = v[vIndex[lq]];
		int& vstart = vStart[lq];

		int ub = upper_bound(vt.begin() + vstart, vt.end(), rq) - vt.begin();
		printf("%d\n", ub - vstart + 1);	
	}

	return 0;
}


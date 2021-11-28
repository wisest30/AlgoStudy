typedef long long ll;

class Solution {
public:
	ll parseNum(string& str)
	{
		ll ret = 0;

		for (char ch : str) ret = ret * 10LL + ch - '0';
		return ret;
	}

	ll getNext(ll cur)
	{
		string curStr = to_string(cur);
		string last(curStr.size(), '9');

		if (last == curStr) return parseNum(last) + 2;

		ll left = 0;
		for (int i = 0; i < (curStr.size() + 1) / 2; i++) left = left * 10LL + curStr[i] - '0';

		string ret = to_string(left + 1);
		for (int i = curStr.size() / 2 - 1; i >= 0; --i) ret += ret[i];

		return parseNum(ret);
	}

	bool isMirror(ll num, ll k)
	{
		string origin;
		string reversed;

		while (num)
		{
			origin += num % k + '0';
			num /= k;
		}

		reversed = origin;
		reverse(reversed.begin(), reversed.end());

		return origin == reversed;
	}

	long long kMirror(int k, int n) {
		ll ans = 0;
		ll cur = 1;

		while (n)
		{
			if (isMirror(cur, k * 1LL))
			{
				n--;
				ans += cur;
			}

			cur = getNext(cur);
		}

		return ans;
	}
};

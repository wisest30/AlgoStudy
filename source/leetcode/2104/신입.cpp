typedef long long ll;

class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int n = nums.size();

		vector<int> maxL(n);
		vector<int> maxR(n);
		vector<int> minL(n);
		vector<int> minR(n);

		for (int i = 0; i < n; i++) maxL[i] = maxR[i] = minL[i] = minR[i] = i;

		stack<int> mxIdxStack;
		stack<int> mnIdxStack;

		for (int i = 0; i < n; i++)
		{
			while (!mxIdxStack.empty() && nums[mxIdxStack.top()] <= nums[i])
			{
				maxR[mxIdxStack.top()] = i;
				mxIdxStack.pop();
			}
			mxIdxStack.push(i);

			while (!mnIdxStack.empty() && nums[mnIdxStack.top()] >= nums[i])
			{
				minR[mnIdxStack.top()] = i;
				mnIdxStack.pop();
			}
			mnIdxStack.push(i);
		}

		while (!mxIdxStack.empty())
		{
			maxR[mxIdxStack.top()] = n;
			mxIdxStack.pop();
		}

		while (!mnIdxStack.empty())
		{
			minR[mnIdxStack.top()] = n;
			mnIdxStack.pop();
		}

		for (int i = n - 1; i >= 0; --i)
		{
			while (!mxIdxStack.empty() && nums[mxIdxStack.top()] < nums[i])
			{
				maxL[mxIdxStack.top()] = i;
				mxIdxStack.pop();
			}
			mxIdxStack.push(i);

			while (!mnIdxStack.empty() && nums[mnIdxStack.top()] > nums[i])
			{
				minL[mnIdxStack.top()] = i;
				mnIdxStack.pop();
			}
			mnIdxStack.push(i);
		}

		while (!mxIdxStack.empty())
		{
			maxL[mxIdxStack.top()] = -1;
			mxIdxStack.pop();
		}

		while (!mnIdxStack.empty())
		{
			minL[mnIdxStack.top()] = -1;
			mnIdxStack.pop();
		}

		ll ans = 0LL;

		for (int i = 0; i < n; i++)
		{
			ans += 1LL * nums[i] * (maxR[i] - i) * (i - maxL[i]);
			ans -= 1LL * nums[i] * (minR[i] - i) * (i - minL[i]);
		}

		return ans;
	}
};

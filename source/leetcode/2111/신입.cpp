
typedef long long ll;

typedef int node_type;

node_type INIT = 0;
node_type node_calc(node_type n1, node_type n2) { return max(n1, n2); }

class Solution {
public:

	struct segment_tree {
		int tree_n;
		vector<node_type> tree;

		void init(vector<node_type>& v) {
			tree.resize(4 * v.size() + 1);
			for (int i = 0; i < tree.size(); i++)
				tree[i] = INIT;

			tree_n = 1;
			while (tree_n < v.size()) tree_n <<= 1;
			for (int i = 0; i < v.size(); i++)
				tree[tree_n + i - 1] = v[i];

			for (int i = tree_n - 2; i >= 0; i--)
				tree[i] = node_calc(tree[i * 2 + 1], tree[i * 2 + 2]);
		}

		void init(int vn) {
			vector<node_type> v(vn + 1, INIT);
			init(v);
		}

		void recalc(int position) {
			while (position != 0) {
				position = (position - 1) >> 1;
				tree[position] = node_calc(tree[position * 2 + 1], tree[position * 2 + 2]);
			}
		}
		// position에 기존 값과 v를 node_calc한 결과를 넣음
		void update_calc(int position, node_type v) {
			position += tree_n - 1;
			tree[position] = node_calc(tree[position], v);
			recalc(position);
		}

		node_type query(int a, int b, int idx, int left, int right) {
			if (right <= a || left >= b) return INIT;
			if (left >= a && right <= b) return tree[idx];
			int mid = (left + right) / 2;
			return node_calc(query(a, b, idx * 2 + 1, left, mid), query(a, b, idx * 2 + 2, mid, right));
		}
		node_type query(int a, int b) { // [a,b)
			return query(a, b, 0, 0, tree_n);
		}
	}smtree;

	int ans;
	int n;

	void solve(vector<int>& arr)
	{
        vector<int> newArr = arr;
        sort(newArr.begin(), newArr.end());
        
        for(int i=0;i<arr.size();i++) arr[i] = lower_bound(newArr.begin(), newArr.end(), arr[i]) - newArr.begin();
        
		vector<int> dp(arr.size());
		int localAns = 0;

		smtree.init(arr.size()+1);

		for (int i = 0; i < arr.size(); i++)
		{
			dp[i] = smtree.query(0, arr[i] + 1) + 1;
			smtree.update_calc(arr[i], dp[i]);
			localAns = max(localAns, dp[i]);
		}

		ans += arr.size() - localAns;
	}

	int kIncreasing(vector<int>& arr, int k) {
		vector<int> newArr[1'00000+5];
		n = arr.size();

		for (int i = 0; i < n; i++) newArr[i % k].push_back(arr[i]);
		for (int i = 0; i < k; i++) solve(newArr[i]);

		return ans;
	}
};

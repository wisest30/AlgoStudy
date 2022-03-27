struct Entity
{
	char ch;
	int len;
};

struct Node
{
	int mxLen;
	Entity left;
	Entity right;
};

Node nodes[4'00000 + 5];

class Solution {
public:
	void update(string& s, int node, int st, int ed, int idx)
	{
		if (st == ed)
		{
			nodes[node].left.ch = nodes[node].right.ch = s[st];
			nodes[node].mxLen = nodes[node].left.len = nodes[node].right.len = 1;
			return;
		}

		if (st > idx || idx > ed) return;

		update(s, node * 2, st, (st + ed) / 2, idx);
		update(s, node * 2 + 1, (st + ed) / 2 + 1, ed, idx);

		nodes[node].left.ch = nodes[node * 2].left.ch;

		if (nodes[node * 2].left.len == (st + ed) / 2 - st + 1 && nodes[node * 2].left.ch == nodes[node * 2 + 1].left.ch)
		{
			nodes[node].left.len = nodes[node * 2].left.len + nodes[node * 2 + 1].left.len;
		}
		else nodes[node].left.len = nodes[node * 2].left.len;


		nodes[node].right.ch = nodes[node * 2 + 1].right.ch;

		if (nodes[node * 2 + 1].right.len == ed - (st + ed) / 2 && nodes[node * 2 + 1].right.ch == nodes[node * 2].right.ch)
		{
			nodes[node].right.len = nodes[node * 2].right.len + nodes[node * 2 + 1].right.len;
		}
		else nodes[node].right.len = nodes[node * 2 + 1].right.len;

		nodes[node].mxLen = max({ nodes[node].left.len, nodes[node].right.len, nodes[node * 2].mxLen, nodes[node * 2 + 1].mxLen });

		if (nodes[node * 2].right.ch == nodes[node * 2 + 1].left.ch)
		{
			nodes[node].mxLen = max(nodes[node].mxLen, nodes[node * 2].right.len + nodes[node * 2 + 1].left.len);
		}
	}

	vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
		vector<int> ans;

		for (int i = 0; i < s.size(); i++) update(s, 1, 0, (int)s.size() - 1, i);
		for (int i = 0; i < queryCharacters.size(); i++)
		{
			s[queryIndices[i]] = queryCharacters[i];
			update(s, 1, 0, (int)s.size() - 1, queryIndices[i]);
			ans.push_back(nodes[1].mxLen);
		}

		return ans;
	}
};

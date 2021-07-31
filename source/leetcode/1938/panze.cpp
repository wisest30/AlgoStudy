struct Query {
  Query(const int _idx, const int _num) : idx(_idx), num(_num) {}
  const int idx;
  const int num;
};

struct Node {
  vector<int> childs;
  vector<Query> queries;
};

class BitTrie {
 public:
  BitTrie(const int _depth)
    : depth(_depth)
    , cnts(1 << (_depth + 1), 0)
    , mask((1 << depth) - 1) {    }

  void Insert(int num) {
    int now = 0;
    for (int d = depth - 1; d >= 0; --d) {
      const int bit = (num >> d) & 0x1;
      now = now * 2 + 1 + bit;
      ++cnts[now];
    }
  }

  void Erase(int num) {
    int now = 0;
    for (int d = depth - 1; d >= 0; --d) {
      const int bit = (num >> d) & 0x1;
      now = now * 2 + 1 + bit;
      --cnts[now];
    }
  }

  int GetMaximumDifference(int num) {
    int operand = 0;
    const int best = num ^ mask;

    int prev = 0;
    for (int d = depth - 1; d >= 0; --d) {
      int bit = (best >> d) & 0x1;
      int now = prev * 2 + 1 + bit;
      if (cnts[now] > 0) {
        operand = (operand << 1) | bit;
        prev = now;
        continue;
      }

      bit = bit ? 0 : 1;
      now = prev * 2 + 1 + bit;
      operand = (operand << 1) | bit;
      prev = now;
    }
    return num ^ operand;
  }

 private:
  vector<int> cnts;
  const int depth;
  const int mask;
};

class Solution {
public:
  Solution() : bit_trie(18) {}

  void Travel(int now) {
    bit_trie.Insert(now);

    for (const auto& query : nodes[now].queries) {
      ret[query.idx] = bit_trie.GetMaximumDifference(query.num);
    }

    for (const auto next : nodes[now].childs) Travel(next);

    bit_trie.Erase(now);
  }

  vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
    nodes.resize(parents.size());
    ret.resize(queries.size());
    int root = -1;
    int i = 0;
    for (auto parent : parents) {
      if (parent == -1) root = i;
      else nodes[parent].childs.push_back(i);
      ++i;
    }

    i = 0;
    for (auto query : queries) {
      nodes[query[0]].queries.push_back(Query(i, query[1]));
      ++i;
    }

    Travel(root);

    return ret;
  }

  vector<Node> nodes;
  vector<int> ret;
  BitTrie bit_trie;
};
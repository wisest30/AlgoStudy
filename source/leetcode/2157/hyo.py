class Solution:
    def groupStrings(self, words: List[str]) -> List[int]:
        n = len(words)
        G = [i for i in range(n)]
        
        def find(x) :
            if G[x] == x : return G[x]
            G[x] = find(G[x])
            return G[x]

        def merge(x, y) :
            G[find(y)] = find(x)
        
        def str_to_bit(s) :
            ret = 0
            for c in s : ret |= 1 << (ord(c) - ord('a'))
            return ret

        def merge_one_flip(key, idx) :
            for i in range(26) :
                other_key = key ^ (1 << i)
                if other_key in idx_dict : merge(idx_dict[other_key], idx)
        
        def merge_one_move(key, idx) :
            one = [i for i in range(26) if key & (1 << i)]
            zero = [i for i in range(26) if not (key & (1 << i))]
            for i in one :
                for j in zero :
                    other_key = key ^ (1 << i) ^ (1 << j)
                    if other_key in idx_dict :
                        merge(idx_dict[other_key], idx)

        idx_dict = dict()
        for i in range(n) :
            key = str_to_bit(words[i])
            if key in idx_dict : merge(idx_dict[key], i)
            else : idx_dict[key] = i
            
            merge_one_flip(key, i)
            merge_one_move(key, i)
            
        counter_groups = Counter()
        for i in range(n) :
            counter_groups[find(i)] += 1
            
        return [len(counter_groups), max(counter_groups.values())]

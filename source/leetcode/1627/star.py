class Solution:
    def areConnected(self, n, threshold, queries):
        union_set = [ i for i in range(n + 1)]
        
        def do_find(u):
            nonlocal union_set
            if union_set[u] == u: return u
            union_set[u] = do_find(union_set[u])
            return union_set[u]

        def do_union(u, v):
            nonlocal union_set
            u = do_find(u)
            v = do_find(v)
            union_set[v] = u
        
        for u in range(threshold + 1, n + 1):
            for v in range(2*u, n + 1, u):
                do_union(u, v)

        answers = []
                
        for u, v in queries:
            if do_find(u) == do_find(v):
                answers.append(True)
            else:
                answers.append(False)
        return answers

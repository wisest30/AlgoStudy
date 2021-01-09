class Solution {
    class Trie {
        Trie[] child;
        int value;
        
        public Trie() {
            child = new Trie[2];
        }
        
        public void push(int x, int depth) {
            if(depth == 32) {
                value = x;
                return;
            }

            Boolean right = (x & (1 << (31 - depth))) != 0;
            int idx = right ? 1 : 0;
            if(child[idx] == null)
                child[idx] = new Trie();
            child[idx].push(x, depth + 1);                
        }
        
        public int find(int x, int depth) {
            if(depth == 32)
                return value ^ x;
            
            Boolean right = (x & (1 << (31 - depth))) == 0;
            int idx = right ? 1 : 0;
            if(child[idx] == null)
                idx ^= 1;
            
            return child[idx].find(x, depth + 1);            
        }
    }
    
    public int[] maximizeXor(int[] nums, int[][] queries) {
        for(int i = 0; i < queries.length; ++i)
            queries[i] = new int[]{queries[i][0], queries[i][1], i, -1};

        Arrays.sort(nums);
        Arrays.sort(queries, (a, b) -> a[1] - b[1]);
            
        Trie root = new Trie();
        for(int i = 0, j = 0; i < queries.length; ++i) {
            while(j < nums.length && nums[j] <= queries[i][1]) {
                root.push(nums[j], 0);
                j++;
            }
            
            if(j == 0)
                continue;
            
            queries[i][3] = root.find(queries[i][0], 0);
        }
        
        Arrays.sort(queries, (a, b) -> a[2] - b[2]);
        int[] ret = new int[queries.length];
        for(int i = 0; i < queries.length; ++i)
            ret[i] = queries[i][3];
        
        return ret;
    }
}

class Solution {
public:
    struct TrieNode
    {
        TrieNode* children[26];
        int cnt;
        
        void init()
        {
            for(int i=0;i<26;i++) children[i] = NULL;
            cnt = 0;
        }
        
        ~TrieNode()
        {
            for(int i=0;i<26;i++)
            {
                if(children[i]) delete children[i];
            }
            cnt = 0;
        }
    };
    
    struct Trie
    {
        TrieNode root;
        
        Trie()
        {
            root.init();
        }
        
        void add(string& str)
        {
            TrieNode* cur = &root;
            
            for(char ch : str)
            {
                if(cur->children[ch-'a'] == NULL) 
                {
                    cur->children[ch-'a'] = new TrieNode();
                    cur->children[ch-'a']->init();
                }
                cur = cur->children[ch-'a'];
                cur->cnt = cur->cnt + 1;
            }
        }
        
        int getCnt(string& str)
        {
            TrieNode* cur = &root;
            int ret = 0;
            
            for(char ch : str)
            {
                cur = cur->children[ch-'a'];
                ret += cur->cnt;
            }
            
            return ret;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        
        for(string& word : words) trie.add(word);
        
        vector<int> ans;
        
        for(string& word : words) ans.push_back(trie.getCnt(word));
        
        return ans;
    }
};

class Solution {
public:
    struct Node {
        string val;
        map<string, Node*> C;
        bool deleted = false;
        string key, pack;

        void push(vector<string>& p, int i) {
            if(i == p.size()) return;
            if(C.count(p[i]) == 0) {
                C[p[i]] = new Node();
                C[p[i]]->val = p[i];
            }
            
            C[p[i]]->push(p, i+1);
        }
    };
    
    map<string, int> cnt;
    void dfs(Node* cur) {
        string& h = cur->key;
        for(auto& p : cur->C) {
            auto* nxt = p.second;
            dfs(nxt);
            h += nxt->pack;
        }
        
        cnt[h]++;        
        cur->pack = string("(") + cur->val + h + ")";
    }
    
    void dfs2(Node* cur) {
        if(!cur->C.empty() && cnt[cur->key] > 1) {
            cur->deleted = true;
            return;
        }

        for(auto& p : cur->C) {
            auto& nxt = p.second;
            dfs2(nxt);
            if(nxt->deleted)
                cur->C.erase(nxt->val);
        }
    }
    
    vector<vector<string>> ans;
    void dfs3(Node* cur, vector<string>& p) {
        if(!cur->val.empty()) {
            p.push_back(cur->val);
            ans.push_back(p);
        }
        
        for(auto& pp : cur->C) {
            auto& nxt = pp.second;
            dfs3(nxt, p);
        }
        
        if(!cur->val.empty())
            p.pop_back();
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for(auto& p : paths) {
            root->push(p, 0);
        }
    
        dfs(root);
        dfs2(root);
        
        vector<string> p;
        dfs3(root, p);
        return ans;
    }
};

typedef long long ll;

struct node
{
    int val;
    node* left;
    node* right;
    
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    node* root;
    const ll mod = 1e9+7;
    ll fac[1000+5] = {1, };
    ll invFac[1000+5] = {1, };
    
    int sz[1000+5];
    ll ans[1000+5];
    
    ll getPower(ll num, ll pow)
    {
        ll ret = 1;
        ll mul = num;
        
        while(pow)
        {
            if(pow%2) ret = (ret * mul) % mod;
            mul = (mul * mul) % mod;
            pow /= 2;
        }
        
        return ret;
    }
    
    void init()
    {
        for(int i=1;i<=1000;i++) fac[i] = (fac[i-1]*i)%mod;
        invFac[1000] = getPower(fac[1000], mod-2);
        for(int i=999;i>=1;--i) invFac[i] = (invFac[i+1]*(i+1))%mod;
    }
    
    void addNode(int num)
    {
        if(root == NULL) 
        {
            root = new node(num);
            return;
        }
        
        node* cur = root;
        
        while(true)
        {
            if(num < cur->val)
            {
                if(cur->left) cur = cur->left;
                else
                {
                    cur->left = new node(num);
                    return;
                }
            }
            else
            {
                if(cur->right) cur = cur->right;
                else
                {
                    cur->right = new node(num);
                    return;
                }
            }
        }
    }
    
    void calc(node* cur)
    {
        ll lCnt = 1;
        ll rCnt = 1;
        int lSz = 0;
        int rSz = 0;
        
        if(cur->left) 
        {
            calc(cur->left);
            lCnt = ans[cur->left->val];
            lSz = sz[cur->left->val];
        }
        if(cur->right)
        {
            calc(cur->right);
            rCnt = ans[cur->right->val];
            rSz = sz[cur->right->val];
        }
        
        sz[cur->val] = lSz + rSz + 1;
        ans[cur->val] = (lCnt * rCnt)%mod;
        ans[cur->val] = (ans[cur->val] * fac[(lSz+rSz)])%mod;
        ans[cur->val] = (ans[cur->val] * invFac[lSz])%mod;
        ans[cur->val] = (ans[cur->val] * invFac[rSz])%mod;
    }
    
    int numOfWays(vector<int>& nums) {
        init();
        for(int num : nums) addNode(num);
        calc(root);
        return ans[root->val]-1;
    }
};

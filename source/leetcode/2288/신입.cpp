class Solution {
public:
    int discount;
    
    string applyDiscount(const string &word)
    {
        if(word[0] != '$') return word;
        if(word.size() == 1) return word;
        if(word.size() > 1 && word[1] < '0' || word[1] > '9') return word;
        
        char ans[100]{};
        long long price = 0;
        
        for(int i=1;i<word.size();i++)
        {
            if(word[i] < '0' || word[i] > '9') return word;
            price = price * 10LL + word[i] - '0';
        }
        
        sprintf(ans, "%.2f", 1.0*price*(100-discount)/100);
        
        string ret = "$";
        
        for(int i=0;ans[i];i++) ret += ans[i];
        
        return ret;
    }
    
    string discountPrices(string sentence, int discount) {
        sentence += " ";
        this->discount = discount;
        
        string ans;
        
        string temp;
        
        for(char ch : sentence)
        {
            if(ch == ' ')
            {
                ans += applyDiscount(temp);
                ans += " ";
                temp = "";
            }
            else temp += ch;
        }
        
        ans.pop_back();
        
        return ans;
    }
};

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8)
            return false;
        
        bool l = false, u = false, d = false, s = false;
        for(auto i = 0; i < password.size(); ++i) {
            if(i + 1 < password.size() && password[i] == password[i+1])
                return false;
            
            auto c = password[i];
            if(islower(c)) l = true;
            else if(isupper(c)) u = true;
            else if(isdigit(c)) d = true;
            else s = true;
        }
        
        return l && u && d && s;
    }
};

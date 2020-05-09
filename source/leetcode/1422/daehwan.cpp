class Solution {
	public:
		int maxScore(string s) {
			int l = s.length();
			int one  = 0;
			for(auto& c : s){
				if(c=='1') one++;
			}
			int cur = one;
			if(s[0]=='1') cur--;
      else cur++;
			int maxy = cur;
			for(int i=1; i<l-1; i++){
				if(s[i]=='0') cur++;
				else cur--;
				maxy = max(maxy, cur);
			} 
			return maxy;
		}
};

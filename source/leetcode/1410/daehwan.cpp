class Solution {
	public:
		string entityParser(string t) {
			string ret="";
			vector<vector<string>> rep={{"&quot;","\""}, {"&apos;","\'"},{"&amp;","&"},{"&gt;",">"},{"&lt;","<"},{"&frasl;","/"}};
			vector<vector<int>> repi(6);
			for(int i=0; i<6; i++){
				size_t pos = t.find(rep[i][0],0);
				while(pos != string::npos){
          t.replace(pos,rep[i][0].size(),rep[i][1]);
					pos = t.find(rep[i][0],pos+1);
				}
			}
			return t;
		}
};

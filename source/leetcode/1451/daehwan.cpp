class Solution {
public:
  vector<vector<string>> ss(100001);
  string::size_type i=0;
  string::size_type j=0;

  while(1){
    j = t.find(" ", i);
    if(j != string::npos){
      string tt = t.substr(i, j-i);
      cout << tt << endl;
      i = j+1;
      ss[tt.size()].push_back(tt);
    }
    else{
      string tt = t.substr(i, t.size()-i);
      cout << tt << endl;
      ss[tt.size()].push_back(tt);
      break;
    }
  }

  string ret = "";
  for(int i=0; i<100001; i++){
    if(ss[i].empty()) continue;
    for(int j=0; j<(int)ss[i].size(); j++){
      ret += ss[i][j];
      ret += " ";
    }
  }
  ret.pop_back();
  ret[0] = ret[0]-32;
  return ret;
    
    }
};

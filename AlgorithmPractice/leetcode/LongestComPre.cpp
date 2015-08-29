class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int len=strs.size();
		string s;
		if(len==0) 
			return s;
		
		int j=0;
		char t;
		while(true){
			t=strs[0][j];
			if(t==0) 
				return s;
			for(int i=1;i<len;i++){
				if(strs[i][j]!=t) 
					return s;
			}
			s.insert(s.end(),t);
			j++;
		}
    }
};
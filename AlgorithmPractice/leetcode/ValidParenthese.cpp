class Solution {
public:
    bool isValid(string s) {
		for(int i=0;i<s.size();i++){
			switch(s[i]){
				case ')':
					if(i==0||s[i-1]!='(')
						return false;
					else{
						s.erase(s.begin()+i-1);
						s.erase(s.begin()+i-1);
						i=i-2;
					}						
					break;
				case ']':
					if(i==0||s[i-1]!='[')
						return false;
					else{
						s.erase(s.begin()+i-1);
						s.erase(s.begin()+i-1);
						i=i-2;
					}	
					break;
				case '}':
					if(i==0||s[i-1]!='{')
						return false;
					else{
						s.erase(s.begin()+i-1);
						s.erase(s.begin()+i-1);
						i=i-2;
					}	
					break;
				default:
					break;
			}
		}
		if(s.size()==0)
			return true;
		else 
			return false;
    }
};
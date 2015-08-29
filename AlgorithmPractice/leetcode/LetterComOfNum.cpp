class Solution {
public:
	string str[8];
    vector<string> letterCombinations(string digits) {		
		vector<string> re;
		string s;
		string str1[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for(int i=0;i<8;i++){
			str[i]=str1[i];
		}
		int len=digits.size();
		if(len==0) return re;
		find(digits,0,len,re,s);
		return re;
    }
	void find(string dig,int n,int len,vector<string> &re,string s){
		int num=dig[n]-48;
		int alpLen=str[num-2].size();
		for(int i=0;i<alpLen;i++){
			s.insert(s.end(),str[num-2][i]);
			if(n==len-1){
				re.push_back(s);
			}else{
				find(dig,n+1,len,re,s);
			}			
			s.erase(s.end()-1);
		}
	}
};
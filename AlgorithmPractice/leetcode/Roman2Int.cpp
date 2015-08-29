class Solution {
public:
    int romanToInt(string s) {
		int len=s.size();
		if(len==0) return NULL;
        char str[]={'I','X','C','M','V','L','D'};
		map<char,int> m;
		for(int i=0;i<7;i++){
			if(i<4){
				m[str[i]]=i;
			}else{
				m[str[i]]=i-4;
			}
			
		}
		int re=0,num=0;

		for(int i=0;i<len;i++){
			if(i==0){
				num+=cal(s[i]);
			}else{
				if(m[s[i]]!=m[s[i-1]]){
					int nt=cal(s[i]);
					if(nt<num){
						re+=num;
						num=nt;
					}else{
						num=nt-num;
					}
					
				}else if(s[i]!=s[i-1]){
					int nt=cal(s[i]);
					if(nt>num)
						num=nt-num;
					else
						num+=nt;
				}else{
					num+=cal(s[i]);
				}
			}
			if(i==len-1){
				re+=num;
			}
		}
		return re;
    }
	int cal(char c){
		switch(c){
			case 'I':
				return 1;
				break;
			case 'X':
				return 10;
				break;
			case 'C':
				return 100;
				break;
			case 'M':
				return 1000;
				break;
			case 'V':
				return 5;
				break;
			case 'L':
				return 50;
				break;
			case 'D':
				return 500;
				break;
			default:
				return 0;
				break;
		}
	}
};
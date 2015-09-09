class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int rest[2];
		vector<string> re;
		if(n==0)
			return re;
		string r;
		rest[0]=rest[1]=n;
		find(rest,n,re,r);
		return re;

    }
	void find(int* rest,int k,vector<string>& re,string r){
		if(rest[0]==k&&rest[1]==k){
			r.insert(r.end(),'(');
			rest[0]--;
			find(rest,k,re,r);
			rest[0]++;
			r.erase(r.end()-1);
		}
		else if(rest[0]>0||rest[1]>0){
			if(rest[0]>0){
				r.insert(r.end(),'(');
				rest[0]--;
				find(rest,k,re,r);
				rest[0]++;
				r.erase(r.end()-1);
			}
			if(rest[1]>0){
				r.insert(r.end(),')');
				rest[1]--;
				if(rest[1]>=rest[0])
					find(rest,k,re,r);
				rest[1]++;
				r.erase(r.end()-1);
			}	
		}else{
			re.push_back(r);
		}
	}
};
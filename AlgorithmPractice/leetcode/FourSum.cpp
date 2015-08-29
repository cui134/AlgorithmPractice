class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> re;
		vector<int> r;
		int len=nums.size();
		if(len<4) 
			return re;
		sort(nums.begin(),nums.end());
		Find(nums,0,4,len,r,target,re);
		return re;
	}
	void find(vector<int>& nums,int begin,int end,int target,vector<vector<int>> &re,vector<int> r){//find 2 num
		int left=begin;
		int right=end;
		while(left<right){
			int val=nums[left]+nums[right];
			if(val>target){
				while(right>left&&nums[right]==nums[right-1])
					right--;
				right--;
			}else if(val<target){
				while(right>left&&nums[left]==nums[left+1])
					left++;
				left++;
			}else{
				r.push_back(nums[left]);
				r.push_back(nums[right]);
				re.push_back(r);
				r.erase(r.end()-1);
				r.erase(r.end()-1);
				while(right>left&&nums[right]==nums[right-1])
					right--;
				right--;
				while(right>left&&nums[left]==nums[left+1])
					left++;
				left++;
			}
		}
	}
	void Find(vector<int>& nums,int n,int k,int len,vector<int> r,int target,vector<vector<int>> &re){ //find k num
		int lenr=r.size();
		if(lenr<k-2){
			for(int i=n;i<len-k+lenr+1;i++){
				if(i>n&&nums[i]==nums[i-1])
					continue;
				int valMax=0,valMin=0;
				for(int j=0;j<k;j++){
					if(j<lenr){
						valMax+=r[j];
						valMin=valMax;
					}else{
						valMax+=nums[len-(k-j)];
						valMin+=nums[i+j-lenr];
					}
				}
				if(valMax<target)
					continue;
				if(valMin>target)
					continue;
				r.push_back(nums[i]);
				Find(nums,i+1,k,len,r,target,re);
				r.erase(r.end()-1);
			}
		}else{
			int t=0;
			for(int i=0;i<lenr;i++){
				t+=r[i];
			}
			find(nums,n,len-1,target-t,re,r);
		}
	}
};
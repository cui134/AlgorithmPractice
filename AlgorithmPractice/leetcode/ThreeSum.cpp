class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		int i,j,k;
		int len=nums.size();
		if(len<3) return ret;
		sort(nums.begin(),nums.end());
		for(i=0;i<len;i++){
			if(i>0&&nums[i]==nums[i-1])
				continue;
			if(nums[i]>0)
				break;
			if(i<len-2&&(nums[i]+nums[len-2]+nums[len-1])<0)
				continue;
			if(i<len-2&&(nums[i]+nums[i+1]+nums[i+2])>0)
				continue;
			myFind(nums,i+1,len-1,nums[i],ret);
		}
		return ret;
    }
	void myFind(vector<int>& nums,int begin,int end,int target,vector<vector<int>>& ret){
		int left=begin;
		int right=end;
		while(left<right){
			if(nums[left]+nums[right]+target>0){
				right--;
			}
			else if(nums[left]+nums[right]+target<0){
				left++;
			}else{
				vector<int> tt;
				tt.push_back(target);
				tt.push_back(nums[left]);
				tt.push_back(nums[right]);
				ret.push_back(tt);
				while(left<right&&nums[left]==nums[left+1]) left++;
				while(left<right&&nums[right]==nums[right-1]) right--;
				left++;
				right--;
			}
		}
	}
};
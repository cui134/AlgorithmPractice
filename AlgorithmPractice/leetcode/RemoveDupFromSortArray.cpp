class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int k=nums.size();
		if(k==0)
			return 0;
		int len=1;
        int same=nums[0];
		for(int i=1;i<nums.size();i++){
			if(nums[i]!=same){
				len++;
				same=nums[i];
			}else{
				nums.erase(nums.begin()+i);
				i--;
			}
		}
		return len;
    }
};
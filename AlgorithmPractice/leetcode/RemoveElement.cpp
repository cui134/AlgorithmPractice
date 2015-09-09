class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int len=0;
		for(int i=0;i<nums.size();i++){
			len++;
			if(nums[i]==val){
				nums.erase(nums.begin()+i);
				len--;
				i--;
			}
		}
		return len;
    }
};
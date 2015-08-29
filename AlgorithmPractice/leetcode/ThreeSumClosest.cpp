class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int len=nums.size();
		int left=0;
		int right=len-1;
		sort(nums.begin(),nums.end());
		int mindis=9999999;
		int minresult;
		while(left<right){
			int three=(left+right)/2;
			int dis=9999999;
			int result;
			while(three>left&&three<right){
				int d=(nums[left]+nums[three]+nums[right])-target;
				if(abs(d)<dis)
				{
					result=d+target;
					dis=abs(d);
				}else{
					break;
				}
				if(d>0)
					three--;
				else if(d<0)
					three++;
				else
					return target;
			}
			if(dis<=mindis){
				minresult=result;
				mindis=dis;
			}
			if(result>target){
				right--;
			}	
			else if(result<target){
				left++;
			}
			else{
			    return target;
			}
		}
		return minresult;
    }
};
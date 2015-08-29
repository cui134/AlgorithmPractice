
#include "ContainerWithMstWater.h"
using namespace std;
int Solution::maxArea(vector<int> &height){
	int mostWater=0;
	int len=height.size();
	int left=0;
	int right=len-1;
	while(left<right){
		int edge=height[left]>height[right]?height[right]:height[left];
		int cap=edge*(right-left);
		mostWater=mostWater>cap?mostWater:cap;
		if(height[left]<height[right]){
			int k=left+1;
			while(k<right){
				if(height[left]<height[k]){
					break;
				}
				k++;
			}
			left=k;
		}else{
			int k=right-1;
			while(k>left){
				if(height[right]<height[k]){
					break;
				}
				k--;
			}
			right=k;
		}
	}
	return mostWater;
}
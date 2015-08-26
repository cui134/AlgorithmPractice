bool cmp_ptr(int *a, int *b){  
    return *a < *b;  
}  
class Solution {  
public:  
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {  
 
      const int n = nums.size();  
      if(n <= 1 || k == 0) return false;  
 
      vector<int*> num_ptrs(n);  
      for(int i = 0; i < n; i++)  num_ptrs[i] = &nums[i];  
      sort(num_ptrs.begin(), num_ptrs.end(), cmp_ptr);  
 
      for(int i = 0; i < n; i++){  
          for(int j = i + 1; j < n; j++){  
              if(*num_ptrs[j] > *num_ptrs[i] + t) break;                    //the difference between nums[i] and nums[j] is at most t  
              if(abs(num_ptrs[j] - num_ptrs[i]) <= k) return true;          //the difference between i and j is at most k  
          }  
      }  
 
       return false;  
    }  
};  
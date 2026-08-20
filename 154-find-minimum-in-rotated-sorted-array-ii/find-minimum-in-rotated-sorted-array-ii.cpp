class Solution {
public:
    int findMin(vector<int>& nums) {
       int start=0;
       int end=nums.size()-1;
       int ans=INT_MAX;
       while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[start]==nums[mid] && nums[mid]==nums[end]){
            ans = min(ans, nums[start]);
            start++;
            end--;
        
        }
        else if(nums[start]<=nums[mid]){
            ans=min(ans,nums[start]);
            start=mid+1;
        }
        else if(nums[mid]<=nums[end]){
           ans= min(ans,nums[mid]);
            end=mid-1;
        }
        }
        return ans;
    }
};
class Solution {
public:
       bool ispossible(vector<int> nums,int mid,int k){
            int sum=0;
            int part=1;
            int ans;
            for(int it:nums){
                if(sum+it>mid){
                    sum=it;
                    part++;
                }
                else{
                sum+=it;                
            }}
            if(part<=k){
                return true;
            }
            return false;
        }
  
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=end;
       while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(nums,mid,k)){
                ans=min(ans,mid);
                end=mid-1;
            }
            else{
            start=mid+1;
            }
        }
        return ans;
    }
};
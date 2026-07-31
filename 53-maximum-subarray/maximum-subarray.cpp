class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=INT_MIN;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxx=max(curr,maxx);
            if(curr<0){
                curr=0;
            }
        }
        return maxx;
    }
};
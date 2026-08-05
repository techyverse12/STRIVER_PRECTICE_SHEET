class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int gola_ind=-1;
        for(int i=n-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            gola_ind=i-1;
            break;
        }            
        }
        if(gola_ind!=-1){
            int swap_ind =gola_ind;
        for(int j=n-1;j>gola_ind;j--){
            if(nums[j]>nums[gola_ind]){
                swap_ind=j;
                break;
            }
        }
        swap(nums[gola_ind],nums[swap_ind]);}
        reverse(nums.begin()+gola_ind+1,nums.end());
    }
};
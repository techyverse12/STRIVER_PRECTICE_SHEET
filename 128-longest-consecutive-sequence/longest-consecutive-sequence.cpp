class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    sort(nums.begin(),nums.end());
    int longest=1;
    int lastsmaller=INT_MIN;
    int coun=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]-1 == lastsmaller){
            coun++;
            lastsmaller=nums[i];
        }
        else if(lastsmaller !=nums[i] ){
            coun=1;
            lastsmaller=nums[i];
        }
        longest=max(longest,coun);
    }
return longest;
}
};
class Solution {
public:
    void rotate(vector<int>& nums){
    int first=nums[0];
    for(int i=1;i<nums.size();i++){
        nums[i-1]=nums[i];
    }
    nums[nums.size()-1]=first;
    }
    void rev(vector<int>& nums){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    bool issorted(vector<int> nums){
        return is_sorted(nums.begin(), nums.end());
    }
 int minOperations(vector<int>& nums) {
    int n = nums.size();
    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            pos = i;
            break;
        }
    }

    bool forward = true;
    bool backward = true;

    for (int i = 0; i < n; i++) {
        if (nums[(pos + i) % n] != i)
            forward = false;

        if (nums[(pos - i + n) % n] != i)
            backward = false;
    }

    int ans = INT_MAX;

    if (forward) {
        ans = min(ans, pos);
        ans = min(ans, n - pos + 2);
    }

    if (backward) {
        ans = min(ans, n - pos);
        ans = min(ans, pos + 2);
    }

    return ans == INT_MAX ? -1 : ans;
}};
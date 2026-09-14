class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
           return  findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int left=(n+m+1)/2;
        int low=0;
        int high=n;
        while(low<=high){
            int i=(low+high)/2;
            int j=left-i;
            int l1,l2,r1,r2;
            if(i==0){
                l1=INT_MIN;
             }
             else{
                l1=nums1[i-1];
             }
            if(i==n){
                r1=INT_MAX;
            }
            else{
                 r1=nums1[i];
            }
            if(j==0){
                l2=INT_MIN;
            }
            else{
                l2=nums2[j-1];
            }
            if(j==m){
                r2=INT_MAX;
            }
            else{
                r2=nums2[j];
            }
            if(l1>r2){
                high=i-1;
            }
            else if(l2>r1){
                low=i+1;
            }
            else if(l2<=r1 && l1<=r2){
                if((n+m)%2==1){
                    return max(l1,l2);
                }
                else{
                   return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
        }
        return 0.0;
    }
};
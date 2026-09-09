class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int total=nums1.size()+nums2.size();
        int counter=total/2;
        int prev=0;
        int curr=0;
        int timer=0;
            while(i<nums1.size() && j<nums2.size() && timer<=counter){
                prev=curr;
                if(nums1[i]<nums2[j]){
                    curr=nums1[i];
                    i++;
                }
                else{
                    curr=nums2[j];
                    j++;
                }
                timer++;
            }
            while(i<nums1.size() && timer<=counter){
                prev=curr;
                curr=nums1[i];
                i++;
                timer++;
            }
            while(j<nums2.size() && timer<=counter){
                prev=curr;
                curr=nums2[j];
                j++;
                timer++;
            }
            if(total % 2==1){
                return curr;
            }
            else{
                return (prev+curr)/2.0;
            }
    }
};
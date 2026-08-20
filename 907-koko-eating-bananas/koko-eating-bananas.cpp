class Solution {
public:
    bool ispossible(vector<int> piles,int mid,int h){
        long long speed=0;
        for(int it:piles){
        speed+=(it+mid-1)/mid; 
        }
        if(speed<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(piles,mid,h)){
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
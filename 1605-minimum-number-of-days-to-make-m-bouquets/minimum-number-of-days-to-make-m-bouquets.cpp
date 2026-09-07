class Solution {
public:
     bool solve(int mid,vector<int> bloomDay,int m,int k){
      int bouquets=0;
      int seq=0;
      for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
             seq++;
            if(seq==k){
                bouquets++;
                seq=0;
            }
        }
        else{
            if(seq<k){
            seq=0;}
        }
      }
      return bouquets>=m;
      }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        int final=INT_MAX;
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            if(solve(mid,bloomDay,m,k)==1){
             end=mid-1;
             final=min(final,mid);
            }
            else{
                start=mid+1;
            }
        }
        return final;
    }
};
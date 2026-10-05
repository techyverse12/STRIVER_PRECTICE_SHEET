class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        double ans=1;
        if(nn<0){
            nn=-1*nn;
        }
        while(nn>0){
            if(nn%2==1){
             ans*=x;
             }
             x*=x;
             nn/=2;
        }
        if (n < 0) {
         return 1.0 / ans;
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxx=0;
        int profit=0;
        int minprice=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<minprice){
                minprice=prices[i];
            }
            maxx=prices[i]-minprice;
            profit=max(maxx,profit);
            }
            return profit;
        
    }
};
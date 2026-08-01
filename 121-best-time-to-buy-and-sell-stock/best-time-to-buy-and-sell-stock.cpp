class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxx=0;
        int profit=0;
        int min=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
            }
            maxx=prices[i]-min;
            profit=max(maxx,profit);
            }
            return profit;
        
    }
};
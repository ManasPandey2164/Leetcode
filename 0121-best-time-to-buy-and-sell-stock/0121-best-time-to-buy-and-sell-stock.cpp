class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 10000;
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min) min = prices[i];
            ans = max(ans,prices[i]-min);
        }
        return ans;
    }
};
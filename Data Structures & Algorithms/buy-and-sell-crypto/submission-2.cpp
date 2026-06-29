class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minimumPrice = INT_MAX;
        int bestProfit = 0;

        for(int currentPrice : prices){
            int todaysProfit = currentPrice - minimumPrice;
            minimumPrice = min(minimumPrice, currentPrice);
            bestProfit = max(bestProfit, todaysProfit);
        }
        return bestProfit;
    }
};

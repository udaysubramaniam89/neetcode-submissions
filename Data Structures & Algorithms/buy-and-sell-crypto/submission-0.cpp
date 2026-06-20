class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;

        int todays_profit;
        int current_price;
        int minimum_price = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            current_price = prices[i];
            minimum_price = min(current_price, minimum_price);
            todays_profit = current_price - minimum_price;
            result = max(todays_profit, result);
        }
        return result;
    }
};

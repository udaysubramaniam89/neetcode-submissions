class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int oneStepBefore = cost[1];
        int twoStepsBefore = cost[0];

        for(int i = 2; i < n; i++){
            int current = cost[i] + min(oneStepBefore, twoStepsBefore);
            twoStepsBefore = oneStepBefore;
            oneStepBefore = current;
        }
        return min(oneStepBefore, twoStepsBefore);
    }
};
*/
//
// Created by Ahsan Ghani on 2022-08-05.
//
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        return min(minCost(dp, cost, n-1), minCost(dp, cost, n-2));
    }
private:
    int minCost(vector<int>& dp, vector<int>& cost, int n)
    {
        if (n<0)
        {
            return 0;
        }
        if (n==0 || n==1)
        {
            return cost[n];
        }
        if (dp[n] != 0)
        {
            return dp[n];
        }
        dp[n] = cost[n] + min(minCost(dp, cost,n-1), minCost(dp, cost,n-2));
        return dp[n];
    }
};
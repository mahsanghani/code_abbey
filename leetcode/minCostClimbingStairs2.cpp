//
// Created by Ahsan Ghani on 2022-08-05.
//
class Solution {
public:
    int f(vector<int> a, int i){
        if(i<=1)    return a[i];
        int pick =  f(a, i-1);
        int nonpick = f(a, i-2);
        return  a[i] + min(pick, nonpick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(f(cost, n-1), f(cost, n-2));
    }
};
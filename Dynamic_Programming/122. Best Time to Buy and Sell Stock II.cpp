#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int idx, int buy,vector<int> &prices ,int n,vector<vector<int>>&dp){
        if(idx==n) return 0;

        int profit=0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            profit=max(-prices[idx]+helper(idx+1,0,prices,n,dp),
            helper(idx+1,1,prices,n,dp));
        }
        else{
            profit=max(prices[idx]+helper(idx+1,1,prices,n,dp),
            helper(idx+1,0,prices,n,dp));
        }
        return dp[idx][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,prices,n,dp);
    }
};
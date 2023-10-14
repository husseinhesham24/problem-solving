class Solution {
public:

    int solve(vector<int>& cost, vector<int>& time, int i, int rem, vector<vector<int>>&dp)
    {
        if(rem<=0)
        {
            return 0;
        }

        if(i>=time.size())
        {
            return 1e9;
        }

        if(dp[i][rem]!=-1)
        {
            return dp[i][rem];
        }
        else
        {
            int notTaken = solve(cost, time, i+1, rem, dp);
            int taken = cost[i] + solve(cost, time, i+1, rem - time[i] -1, dp);
            return dp[i][rem] = min(notTaken, taken);
        }
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return solve(cost, time, 0, time.size(), dp);
    }
};
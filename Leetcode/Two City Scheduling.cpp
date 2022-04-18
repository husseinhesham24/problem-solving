class Solution {
public:
    int mem[105][55][55]{};
    int m, n;

    int solve(vector<vector<int>>& x, int i, int a, int b)
    {
        if(i==n)
        {
            return 0;
        }
        
        if(mem[i][a][b]!=-1)
        {
            return mem[i][a][b];
        }
        
        int ans = 1e9+7;
        
        
        if(a<m && b<m)
        {
            ans = min(x[i][0]+solve(x, i+1, a+1, b), x[i][1]+solve(x, i+1, a, b+1));
        }
        else if(a<m)
        {
            ans = min(ans, x[i][0]+solve(x, i+1, a+1, b));
        }
        else
        {
            ans = min(ans, x[i][1]+solve(x, i+1, a, b+1));
        }
        
        return mem[i][a][b] = ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(mem, -1, sizeof(mem));
        n = costs.size();
        m = n/2;
        return solve(costs, 0, 0, 0);
    }
};
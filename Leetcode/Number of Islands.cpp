class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    int vis[305][305];
    bool valid(int i, int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void dfs(vector<vector<char>>&x, int i, int j)
    {
        x[i][j]='0';
        for(int k=0;k<4;k++)
        {
            int r = dx[k]+i;
            int c = dy[k]+j;
            if(valid(r,c) && x[r][c]=='1')
            {
                dfs(x, r,c);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }      
        }
        return ans;
    }
};
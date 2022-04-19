class Solution {
public:
    
    int n,m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int vis[300][300];
    vector<vector<char>>v;
    
    bool valid(int i, int j)
    {
        return i<n && j<m && i>=0 && j>=0;
    }
    
    void dfs(int i, int j)
    {
        vis[i][j] = 1;
        
        for(int k=0;k<4;k++)
        {
            int a = i + dx[k];
            int b = j + dy[k];
            if(valid(a,b) && v[a][b] =='O' && !vis[a][b])
            {
                dfs(a,b);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        memset(vis, 0, sizeof(vis));
        v = board;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1))
                {
                    dfs(i, j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
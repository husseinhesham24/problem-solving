class Solution {
public:
    
    int n, m;
    int vis[100][100];
    vector<vector<int>>v;
    
    bool valid(int i, int j)
    {
        return i < n && j < m && i >= 0 && j >= 0;
    }

    int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        memset(vis, 0, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        v = grid;
        bool is_rot = true;
        
        while(is_rot)
        {
            is_rot = false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(v[i][j]==2 && vis[i][j]==ans)
                    {
                        for(int k=0; k<4;k++)
                        {
                            int a = i + dx[k];
                            int b = j + dy[k];

                            if(valid(a, b) && v[a][b]==1)
                            {
                                v[a][b] = 2;
                                vis[a][b] = vis[a][b]+ans+1;
                                is_rot = true;
                            }
                        }
                    }
                }
            }
            
            ans++;
        }
        
        
        ans--;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    ans = -1;
                    goto done;
                }
            }
        }
        
        done:
        return ans;
    }
};
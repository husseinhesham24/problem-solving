class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n,m;
    bool valid(int x, int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);    
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        
        if(fresh==0 && q.empty())
        {
            return 0;
        }
        
        int levels=-1;
        
        while(!q.empty())
        {
            int sz = q.size();
            levels++;
            while(sz--)
            {
                pair<int,int>p = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x = dx[i]+p.first;
                    int y = dy[i]+p.second;
                    if(valid(x,y) && grid[x][y]==1)
                    {
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                        
                    }
                }
            }
        }
        
       if(!fresh)
       {
           return levels;
       }
        
        return -1;
    }
};
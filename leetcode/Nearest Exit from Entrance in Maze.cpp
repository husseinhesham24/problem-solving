class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n,m;
    bool valid(int x, int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        n = maze.size();
        m = maze[0].size();
        vector<vector<int>>vis(n, vector<int>(m));
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;
        int level=0;
        while(!q.empty())
        {
            level++;
            int sz = q.size();
            while(sz--)
            {
                pair<int,int>p = q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int x = p.first+dx[i];
                    int y = p.second+dy[i];
                    if(valid(x,y) && maze[x][y]=='.' && vis[x][y]==0)
                    {
                        if(x==0 || y==0 || x==n-1 || y==m-1)
                        {
                            return level;
                        }
                        vis[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};
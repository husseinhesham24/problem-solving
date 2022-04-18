class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int vis[55][55];
    int n=0, m=0;
    int color;
    
    
    bool valid(int i, int j)
    {
        return i<n && i>=0 && j<m && j>=0;
    }
    void ff(vector<vector<int>>&x, int i, int j, int newColor)
    {
        vis[i][j] = 1;
        x[i][j] = newColor;
        for(int k=0;k<4;k++)
        {
            int r = dx[k]+i;
            int c = dy[k]+j;
            if(valid(r,c) && x[r][c]==color && vis[r][c]==0)
            {
                ff(x, r,c,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(vis, 0, sizeof(vis));
        color = image[sr][sc];
        n = image.size();
        m = image[0].size();
        ff(image, sr,sc, newColor);
        return image;
    }
};
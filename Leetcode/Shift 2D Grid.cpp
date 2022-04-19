class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int l = n*m;
        vector<vector<int>>ans(n);
        vector<int>x(n*m);
        int kk=k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                x[kk%l] = grid[i][j];
                kk++;
            }
        }
        
        kk=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                grid[i][j] = x[kk]; 
                kk++;
            }
        }
        
        return grid;
    }
};
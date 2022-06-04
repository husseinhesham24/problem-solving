class NumMatrix {
public:
    vector<vector<int>>x;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        x.resize(n+1, vector<int>(m+1));
          
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                x[i][j] += x[i-1][j]+x[i][j-1]-x[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++;
        r2++;
        c1++;
        c2++;
        return x[r2][c2]-x[r2][c1-1]-x[r1-1][c2]+x[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class Solution {
public:
    double mem[105][105];
    double solve(int p, int i, int j)
    {
        if(i<0 || j>i || j<0)
        {
            return 0.0;
        }
        
        if(i==0 && j==0)
        {
            return p;
        }
        
        if(mem[i][j]>-1)
        {
            return mem[i][j];
        }
        
        double l = (solve(p, i-1, j-1)-1)/2.0;
        if(l<0)
        {
            l = 0;
        }
        
        double r = (solve(p, i-1, j)-1)/2.0;
        if(r<0)
        {
            r = 0;
        }
        
        double ans = l+r;
        return mem[i][j] = ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(mem, -1, sizeof(mem));
        return min(solve(poured, query_row, query_glass), 1.0);
    }
};
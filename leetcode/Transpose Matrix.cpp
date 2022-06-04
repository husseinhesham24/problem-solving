class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        vector<vector<int>>ans(m);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[j].push_back(matrix[i][j]);
            }
        }
        
        return ans;
    }
};
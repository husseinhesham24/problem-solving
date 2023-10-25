class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<long>>arr(rowIndex+5, vector<long>(rowIndex+5, 1));
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=1;j<=i;j++)
            {
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
                if(i==rowIndex-1)
                {
                    ans.push_back(arr[i][j]);
                }
            }
        }
        if(rowIndex)
            ans.push_back(1);

        return ans;
    }
};
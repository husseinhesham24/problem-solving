class Solution {
public:
    #define pi pair<int, int>
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                cnt+=(mat[i][j]==1?1:0);
            }
            pq.emplace(cnt,i);
        }
        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
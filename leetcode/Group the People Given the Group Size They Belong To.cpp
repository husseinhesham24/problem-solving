class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>ans;
        vector<pair<int,int>>x(n);
        for(int i=0;i<n;i++)
        {
            x[i] = {groupSizes[i],i};
        }

        sort(x.begin(), x.end());
        
        vector<int>temp;
        temp.push_back(x[0].second);
        int j = 1;
        for(int i=1;i<n;i++)
        {
            if(x[i].first!=x[i-1].first || j==x[i].first)
            {
                ans.push_back(temp);
                temp.clear();
                j = 1;
                temp.push_back(x[i].second);
            }
            else
            {
                temp.push_back(x[i].second);
                j++;
            }
        }

        ans.push_back(temp);
        return ans;
    }
};
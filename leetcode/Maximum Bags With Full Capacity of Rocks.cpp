class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0;
        int n = capacity.size();
        vector<int>rem;
        for(int i=0;i<n;i++)
        {
            rem.push_back(capacity[i]-rocks[i]);
        }

        sort(rem.begin(), rem.end());
        for(int i=0;i<n && additionalRocks>0;i++)
        {
            int temp = min(additionalRocks, rem[i]);
            additionalRocks-=temp;
            rem[i]-=temp;
            if(rem[i]==0)
            {
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans = max(ans, max(0, maxi - prices[i]));
            //cout<<ans<<" "<<prices[i]<<" "<<maxi<<endl;
            maxi = max(maxi, prices[i]);
        }

        return ans;
    }
};
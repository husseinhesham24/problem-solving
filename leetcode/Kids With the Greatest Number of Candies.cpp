class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        int n = candies.size();
        maxi = *max_element(candies.begin(), candies.end());

        vector<bool>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = (candies[i]+extraCandies>=maxi);
        }

        return ans;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        vector<int>x = nums;
        sort(x.begin(), x.end());
        int n = nums.size();
        long long ans=0;
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n-1;i++)
        {
            if(x[i]==x[i+1])
            {
                cnt++;
            }
            else
            {
                cnt++;
                if(maxi<cnt)
                {
                    maxi = cnt;
                    ans = x[i];
                }
                cnt=0;
            }
        }
        cnt++;
        if(maxi<cnt)
        {
            maxi = cnt;
            ans = x[n-1];
        }
        return ans;
    }
};
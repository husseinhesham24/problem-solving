class Solution {
public:

    int BS(int &target, vector<int>&cum, int &n)
    {   
        int st=0, en = n-1, ans=-1;
        while(st<=en)
        {
            int temp = (st+en)/2;
            
            if(cum[temp]==target)
            {
                return temp+1;
            }
            else if(cum[temp]<target)
            {
                st = temp+1;
                ans = temp;
            }
            else
            {
                en = temp-1;
            }
        }
        return (ans==-1?0:ans+1);
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int>cum(n);
        sort(nums.begin(), nums.end());
        cum[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            cum[i] = cum[i-1]+nums[i];
        }

        int m = queries.size();
        vector<int>ans(m);

        for(int i=0;i<m;i++)
        {
            ans[i] = BS(queries[i], cum, n);
        }

        return ans;
    }
};
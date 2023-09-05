class Solution {
public:
    
    int bs(int st, int en, int tar, int idx, vector<pair<int,int>>&x)
    {
        while(st<=en)
        {
            int mid = st+(en-st)/2;
            if(x[idx].first+x[mid].first==tar)
            {
                return mid;
            }
            else if(x[idx].first+x[mid].first<tar)
            {
                st = mid+1;
            }
            else
            {
                en = mid-1;
            }
        }

        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>x(n);
        for(int i=0;i<n;i++)
        {
            x[i] = {nums[i],i};
        }

        sort(x.begin(), x.end());

        vector<int>ans(2);
        int flag=0;
        for(int i=0;i<=n-1;i++)
        {
            int ft = bs(i+1,n-1, target, i, x);
            if(ft!=-1)
            {
                cout<<i<<" "<<ft<<endl;
                ans[0] = x[i].second;
                ans[1] = x[ft].second;
                break;
            }
        }

        return ans;
    }
};
class Solution {
public:

    int bin(int st, int en, int idx, int tar, vector<pair<int,int>>& x)
    {
        while(st<=en)
        {
            int mid = st+(en-st)/2;
            if((x[mid].first+x[idx].first)==tar)
            {
                //cout<<x[mid].first+x[idx].first<<" "<<mid<<" "<<idx<<" "<<tar<<" "<<x[idx].first<<" "<<x[mid].first<<endl;
                return x[mid].second;
            }
            else if((x[mid].first+x[idx].first)<tar)
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
            x[i].first = nums[i];
            x[i].second = i;
        }
        
        sort(x.begin(), x.end());
        vector<int>ans(2);
        for(int i=0;i<n-1;i++)
        {
            int temp = bin(i+1, n-1, i, target, x);
            if(temp!=-1)
            {
                ans[0] = x[i].second;
                ans[1] = temp;
                break;
            }
        }
        return ans;
    }
};
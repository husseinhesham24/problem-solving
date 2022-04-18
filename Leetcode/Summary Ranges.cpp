class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<long long>x;
        for(int i=0;i<nums.size();i++)
        {
            x.push_back(nums[i]);
        }
        vector<string> ans;
        long long n = x.size();
        if(n==0)
        {
            return ans;
        }
        string str = to_string(x[0]);
        long long last = x[0];
        long long first = x[0];
        bool flag = false;
        for(int i=1;i<n;i++)
        {
            if(x[i]-x[i-1]==1)
            {
                last = x[i];
                if(i==n-1)
                {
                    flag = true;
                }
            }
            else
            {
                if(first==last)
                {
                    str = to_string(last);
                }
                else
                {
                    str = to_string(first) + "->" + to_string(last);
                }
                ans.push_back(str);
                first = x[i];
                last = x[i];
            }
        }
    
        if(first==last)
        {
            str = to_string(last);
        }
        else
        {
            str = to_string(first) + "->" + to_string(last);
        }
        ans.push_back(str);
        
        return ans;
    }
};
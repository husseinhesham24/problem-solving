class Solution {
public:
    
    vector<int>nums;
    int get_prefix(int st, int en, vector<int>&cum)
    {
        if(st==0)
        {
            return cum[en];
        }

        return cum[en]-cum[st-1];
    }
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                nums.push_back(1);
            }
            else
            {
                nums.push_back(0);
            }
        }
        
        
        vector<int>cum(n);
        cum[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            cum[i] = cum[i-1]+nums[i];
        }

        int mini = get_prefix(0,n-1,cum);
        int ans=0;
        
        //cout<<"0"<<" "<<get_prefix(0,n-1,cum)<<endl;
        for(int i=1;i<n;i++)
        {
            int sum=((i)-get_prefix(0,i-1, cum))+(get_prefix(i,n-1,cum));
            //cout<<i<<" "<<sum<<" "<<((i)-get_prefix(0,i-1, cum))<<" "<<(get_prefix(i,n-1,cum))<<endl;
            if(mini>sum)
            {
                ans = i;
                mini = sum;
            }
        }

        int sum = n-get_prefix(0,n-1,cum);
        //cout<<n<<" "<<n-get_prefix(0,n-1,cum)<<endl;
        if(mini>sum)
        {
            ans = n;
            mini = sum;
        }

        return ans;
    }
};
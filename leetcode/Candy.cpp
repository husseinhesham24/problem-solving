class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int ans=n, i=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }

            int maxi=0;
            while(ratings[i]>ratings[i-1])
            {
                maxi++;
                ans+=maxi;
                i++;
                if(i==n)
                {
                    return ans;
                }
            }

            int mini = 0;
            while(i<n && ratings[i]<ratings[i-1])
            {
                mini++;
                ans+=mini;
                i++;
            }
            ans-=min(maxi, mini);
        }

        return ans;
    }
};
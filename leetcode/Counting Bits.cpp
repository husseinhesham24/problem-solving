class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int temp = i, cnt=0;
            while(temp>0)
            {
                cnt+=(temp%2);
                temp/=2;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};
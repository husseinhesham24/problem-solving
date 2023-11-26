class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>h;
        set<int, greater<int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            h[nums[i]]++;
            s.insert(nums[i]);
        }

        int ans=0;
        sort(nums.rbegin(),nums.rend());
        n = s.size();
        int last=0;
        for(auto it:s)
        {
            if(n==1)
            {
                break;
            }
            ans+=(h[it]+last);
            last += h[it];
            n--;
        }

        return ans;
    }
};
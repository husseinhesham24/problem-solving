class Solution {
public:
    int mem[10005];
    unordered_map<int,int>h;
    vector<int>x;
    int n;
    long long solve(int i)
    {
        if(i==n)
        {
            return 0;
        }
        
        if(mem[i]!=-1)
        {
            return mem[i];
        }
        
        int index = i+1;
        int cur = x[i];
        while(index<n && x[index]<=x[i]+1)
        {
            index++;
        }
        
        
        return mem[i] = max((h[x[i]]*x[i])+solve(index), solve(i+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        memset(mem, -1, sizeof(mem));
        n = nums.size();
        for(int i=0;i<n;i++)
        {
            h[nums[i]]++;
        }
        
        x = nums;
        sort(x.begin(), x.end());
        return solve(0);
    }
};

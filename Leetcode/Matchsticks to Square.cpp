class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(nums.size()<4 || sum%4!=0)
            return false;
        return dfs(nums,nums.size()-1,sum/4,sum/4,sum/4,sum/4);
    }
    
    bool dfs(vector<int>&nums,int i,int s1,int s2,int s3,int s4){
        if(s1==0 and s2==0 and s3==0 and s4==0)
            return true;
        if(s1<0 || s2<0 || s3<0 || s4<0)
            return false;
        if(i<0)
            return false;
        return dfs(nums,i-1,s1-nums[i],s2,s3,s4) || dfs(nums,i-1,s1,s2-nums[i],s3,s4) ||
               dfs(nums,i-1,s1,s2,s3-nums[i],s4) || dfs(nums,i-1,s1,s2,s3,s4-nums[i]);
        
        return true;
        
    }
};
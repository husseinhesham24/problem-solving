class Solution {
public:
    
    bool isValid(vector<int> nums,int n, int m, int mid){
        int assn=1; 
        int sum=0;
        for(int i : nums){
            sum+=i;
            if (sum>mid){
                assn++;
                sum=i;
                if (sum>mid) 
                    return false;
            }
            if (assn>m) 
                return false;
        }
        return true; 
    }
    int splitArray(vector<int>& nums, int m) {
        int n=size(nums); 
        long long  sum=0;
        for(long long  i : nums){
            if (i==INT_MAX)
                return INT_MAX;
            sum+=i;
        }
        if (m==1) 
            return sum;
        long long low=0;
        long high=sum; 
        long long  mid;
        long long  res=INT_MAX;
        while (low<=high){
            mid=low+(high-low)/2;
            if (isValid(nums,n,m,mid)) 
            {
                res=min(res,mid);
                high=mid-1; 
            }
            else 
                low=mid+1;
            
        }
        return res;
    }
};
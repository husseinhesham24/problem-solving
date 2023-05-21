class Solution {
public:
    void merge(vector<int>&nums, int l, int mid, int r)
    {
        int n = nums.size();
        int n1 = (mid-l)+1;
        int n2 = (r-mid);
        int x[n1];
        int y[n2];
        for(int i=0;i<n1;i++)
        {
            x[i] = nums[l+i];
        }
        for(int i=0;i<n2;i++)
        {
            y[i] = nums[mid+i+1];
        }

        int i=0, j=0, k=l;

        while(i<n1 && j<n2)
        {
            if(x[i]<=y[j])
            {
                nums[k] = x[i];
                i++;
            }
            else
            {
                nums[k] = y[j];
                j++;
            }

            k++;
        }

        while(i<n1)
        {
            nums[k] = x[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k] = y[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<int>&x, int l, int r)
    {
        if(l>=r)
        {
            return;
        }

        int mid = l+(r-l)/2;
        mergesort(x, l,mid);
        mergesort(x, mid+1,r);
        merge(x,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
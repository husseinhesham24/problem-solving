class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>x;
        for(auto it:nums1)
        {
            x.push_back(it);
        }

        for(auto it:nums2)
        {
            x.push_back(it);
        }

        sort(x.begin(), x.end());

        int n = x.size();
        return n%2?x[n/2]:(x[n/2-1]+x[n/2])/2.0;
    }
};
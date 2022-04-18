class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int n = nums.size();
        vector<int> x = nums;

        if (n < 3)
        {
            return 0;
        }

        for (int i = 2; i < n; i++)
        {
            if (x[i] - x[i - 1] == x[i - 1] - x[i - 2])
            {   
                if (cnt == 0)
                {
                    cnt += 2;
                }
                else
                {
                    cnt++;
                }
            }
            else
            {
                ans += ((cnt * (cnt - 1)) / 2);
                cnt = 0;
            }
        }

        if (cnt != 0)
        {
            ans += ((cnt * (cnt - 1)) / 2);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>h;
        for(int i=0;i<nums.size();i++)
        {
            h[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto it:h)
        {
            pq.push({it.second, it.first});
        }
        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
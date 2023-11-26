class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int>mp, vis;
        unordered_map<int, vector<int>>chain;
        
        int n = adjacentPairs.size();
        for(int i=0;i<n;i++)
        {
            mp[adjacentPairs[i][0]]++;
            mp[adjacentPairs[i][1]]++;
            chain[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            chain[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int st = 0;
        for(int i=0;i<n;i++)
        {
            if(mp[adjacentPairs[i][0]]==1)
            {
                st = adjacentPairs[i][0];
                break;
            }

            if(mp[adjacentPairs[i][1]]==1)
            {
                st = adjacentPairs[i][1];
                break;
            }
        }

        vector<int>ans;
        ans.push_back(st);
        vis[st]=1;
        while(true)
        {   
            if(vis[chain[st][0]]==0)
            {
                
                ans.push_back(chain[st][0]);
                st = chain[st][0];
                vis[st] = 1;
            }
            else if(mp[st]>1 && vis[chain[st][1]]==0)
            {
                ans.push_back(chain[st][1]);
                st = chain[st][1];
                vis[st] = 1;
            }
            else 
            {
                break;
            }
        }

        return ans;
    }
};
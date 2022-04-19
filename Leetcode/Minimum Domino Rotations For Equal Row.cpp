class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>m_top, m_bot, same;
        int n = tops.size();
        for(int i=0;i<n;i++)
        {
            m_top[tops[i]]++;
            m_bot[bottoms[i]]++;
            if(tops[i]==bottoms[i])
            {
                same[tops[i]]++;
            }
        }
        
        for(int i=1;i<7;i++)
        {
            if(m_top[i]+m_bot[i]-same[i]==n)
            {
                return n-max(m_top[i], m_bot[i]);
            }   
        }
        
        return -1;
    }
};
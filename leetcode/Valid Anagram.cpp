class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>h1,h2;
        for(auto c:s)
        {
            h1[c]++;
        }

        for(auto c:t)
        {
            h2[c]++;
        }

        for(char i='a';i<'z';i++)
        {
            if(h1[i]!=h2[i])
            {
                return false;
            }
        }

        return true;
    }
};
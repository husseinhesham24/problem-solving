class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int>h,h1;
        for(auto c:s)
        {
            h[c]++;
        }

        for(auto c:t)
        {
            h1[c]++;
        }

        char ans = ' ';
        for(auto c:t)
        {
            if(h1[c]>h[c])
            {
                ans = c;
                break;
            }
        }
        return ans;
    }
};
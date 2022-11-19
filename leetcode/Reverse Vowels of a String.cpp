class Solution {
public:
    bool is_vow(char c)
    {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
    }
    string reverseVowels(string s) {
        vector<int>pos;
        for(int i=0;i<s.size();i++)
        {
            if(is_vow(s[i]))
            {
                pos.push_back(i);
            }
        }
        
        for(int i=0, j = pos.size()-1;i<j;i++,j--)
        {
            swap(s[pos[i]], s[pos[j]]);
        }
        
        return s;
    }
};
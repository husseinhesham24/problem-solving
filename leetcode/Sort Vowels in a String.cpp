class Solution {
public:

    static bool is_vowel(char c)
    {   
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string sortVowels(string s) {
        string t = "";
        for(int i=0;i<s.size();i++)
        {
            if(is_vowel(s[i]))
            {
                t+=s[i];
            }
        }

        sort(t.begin(), t.end());

        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(is_vowel(s[i]))
            {
                s[i] = t[j++];
            }
        }

        return s;
    }
};
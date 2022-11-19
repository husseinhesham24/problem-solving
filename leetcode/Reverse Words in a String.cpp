class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string word = "";
        s+=' ';
        for(auto c:s)
        {
            if(c!=' ')
            {
                word+=c;
            }
            else
            {
                if(word.size())
                {
                    words.push_back(word);
                }
                word = "";
            }
        }
        
        
        for(int i=words.size()-1;i>=0;i--)
        {
            for(auto it:words[i])
            {
                word+=it;
            }
            if(i>0)
            {
                word+=' ';
            }
        }
        
        
        return word;
    }
};
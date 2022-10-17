class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        int x[30] = {0};
        for(int i=0;i<n;i++)
        {
            x[sentence[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(x[i]<1)
                return false;
        }
        return true;
    }
};
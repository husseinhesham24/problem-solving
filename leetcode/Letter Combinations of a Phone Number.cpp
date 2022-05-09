class Solution {
public:

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>h;
        h['2'] = "abc";
        h['3'] = "def";
        h['4'] = "ghi";
        h['5'] = "jkl";
        h['6'] = "mno";
        h['7'] = "pqrs";
        h['8'] = "tuv";
        h['9'] = "wxyz";
        
        vector<string>ans;
        int n = digits.size();
        string temp = "";
        if(n==0)
        {
            return ans;
        }
        else if(n==1)
        {
            
            for(int i=0;i<h[digits[0]].size();i++)
            {   
                temp+=h[digits[0]][i];
                ans.push_back(temp);
                temp = "";
            }
        }
        else if(n==2)
        {
            string temp = "";
            for(int i=0;i<h[digits[0]].size();i++)
            {
                
                for(int j=0;j<h[digits[1]].size();j++)
                {
                    temp+=h[digits[0]][i];
                    temp+=h[digits[1]][j];
                    ans.push_back(temp);
                    temp = "";
                }   
            }
        }
        else if(n==3)
        {
            for(int i=0;i<h[digits[0]].size();i++)
            {
                for(int j=0;j<h[digits[1]].size();j++)
                {
                    for(int k=0;k<h[digits[2]].size();k++)
                    {
                        temp+=h[digits[0]][i];
                        temp+=h[digits[1]][j];
                        temp+=h[digits[2]][k];
                        ans.push_back(temp);
                        temp = "";
                    }   
                }   
            }
        }
        else
        {
            for(int i=0;i<h[digits[0]].size();i++)
            {
                for(int j=0;j<h[digits[1]].size();j++)
                {
                    for(int k=0;k<h[digits[2]].size();k++)
                    {
                        for(int l=0;l<h[digits[3]].size();l++)
                        {
                            temp+=h[digits[0]][i];
                                temp+=h[digits[1]][j];
                                temp+=h[digits[2]][k];
                                temp+=h[digits[3]][l];
                                ans.push_back(temp);
                                temp = "";
                        }   
                    }   
                }   
            }
        }
        
        return ans;
    }
};
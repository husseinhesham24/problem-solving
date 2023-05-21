class Trie{
public:

    Trie* children[26];
    bool isleaf;
    Trie(){
        isleaf = false;
        for(int i=0;i<26;i++)
        {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    Trie* root;
public:

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(auto c:word)
        {
            if(curr->children[c-'a']==nullptr)
            {
               curr->children[c-'a'] = new Trie();
            }
            curr = curr->children[c-'a'];
        }
        curr->isleaf = true;
    }
    
    bool search(string word) {
        return search_helper(root, word, 0);
    }

    bool search_helper(Trie* curr, string word, int index)
    {
        if(index==word.size())
        {
            return curr->isleaf;
        }

        char c = word[index];
        if(c=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(curr->children[i]!=nullptr && search_helper(curr->children[i], word, index+1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if(curr->children[c-'a']!=nullptr && search_helper(curr->children[c-'a'], word, index+1))
            {
                return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
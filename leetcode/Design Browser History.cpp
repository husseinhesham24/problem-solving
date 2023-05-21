class BrowserHistory {
public:

    vector<string>sites;
    int cur=-1, n=-1;
    BrowserHistory(string homepage) {
        sites.push_back(homepage);
        cur = 0;
        n++;
    }
    
    void visit(string url) {

        for(int i=n;i>cur;i--)
        {
            sites.pop_back();
        }
        sites.push_back(url);
        cur++;
        n = cur;
    }
    
    string back(int steps) {
        if(cur-steps<0)
        {
            cur = 0;
            return sites[cur];
        }
        else
        {
            cur-=steps;
            return sites[cur];
        }
    }
    
    string forward(int steps) {
        if(cur+steps>n)
        {
            cur = n;
            return sites[n];
        }
        else
        {
            cur+=steps;
            return sites[cur];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
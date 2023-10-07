class MyHashMap {
public:
    vector<list<pair<int,int>>>map;
    const int size = 10007;
    MyHashMap() {
        map.resize(size);
    }
    
    void put(int key, int value) {
        auto &arr = map[key%size];
       
        for(auto &it:arr)
        {
            if(it.first==key)
            {
                it.second = value;
                return;
            }
        }

        arr.push_back({key, value});
    }
    
    int get(int key) {
        
        auto &arr = map[key%size];
    
        for(auto it:arr)
        {
            if(it.first==key)
            {
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        auto &arr = map[key%size];
        arr.remove_if([key](auto n) {return n.first==key;});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
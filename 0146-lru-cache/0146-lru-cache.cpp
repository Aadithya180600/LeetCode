class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> lru;
    LRUCache(int capacity) {
         this->cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;

        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});

        m.erase(it);
        m[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);

        if(m.find(key) != m.end()){
            lru.erase(it->second);
            m.erase(it);
        }

        lru.push_front({key, value});
        m[key] = lru.begin();

        if(m.size() > cap){
            auto it = m.find(lru.rbegin()->first);
            m.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
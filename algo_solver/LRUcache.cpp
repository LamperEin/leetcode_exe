#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int _cap;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _map;

public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    int get(int key) {
        auto it = _map.find(key);
        //如果访问的key不存在
        if(it == _map.end()) return -1;
        //key存在， 把（k, v)换到对头
        pair<int, int> kv = *_map[key];
        _cache.erase(_map[key]);
        _cache.push_front(kv);
        // 更新（key, value) 在 cache中的位置
        _map[key] = _cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        // 要先判断key是否存在
        auto it = _map.find(key);
        if(it  == _map.end()) {
            // key 不存在,判段 cacke 是否满了
            if(_cache.size() == _cap) {
                auto lastpair = _cache.back();
                int lastkey = lastpair.first;
                _map.erase(lastkey);
                _cache.pop_back();
            }
            _cache.push_front(make_pair(key, value));
            _map[key] = _cache.begin();
        } else {
            // key already exists, update value and pop to the top
            _cache.erase(_map[key]);
            _cache.push_front(make_pair(key, value));
            _map[key] = _cache.begin();
        }
    }
};



int main() {

    return 0;
}
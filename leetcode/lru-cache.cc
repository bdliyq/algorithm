// Question: https://leetcode.com/problems/lru-cache/

#include "headers.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if (kvs_.count(key) == 0) {
            return -1;
        }

        int ans = kvs_[key]->second;
        kv_.erase(kvs_[key]);
        kvs_[key] = kv_.insert(kv_.begin(), make_pair(key, ans));
        return ans;
    }

    void set(int key, int value) {
        if (kvs_.count(key) == 0) {
            kvs_[key] = kv_.insert(kv_.begin(), make_pair(key, value));
        } else {
            kv_.erase(kvs_[key]);
            kvs_[key] = kv_.insert(kv_.begin(), make_pair(key, value));
        }

        if (kvs_.size() > capacity_) {
            kvs_.erase(kv_.back().first);
            kv_.pop_back();
        }
    }

private:
    int capacity_;
    list<pair<int, int>> kv_;
    unordered_map<int, list<pair<int, int>>::iterator> kvs_;
};

int main(int argc, char** argv) {
    LRUCache cache(3);
    cache.set(1, 100);
    cache.set(2, 200);
    cache.set(3, 300);
    cache.set(4, 400);
    cache.set(4, 401);
    cache.set(4, 402);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}

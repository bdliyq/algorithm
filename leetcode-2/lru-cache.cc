// Question: https://leetcode.com/problems/lru-cache/

class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if (m_.count(key) == 0) {
            return -1;
        }

        auto iter = m_[key];
        int ans = iter->second;
        l_.erase(iter);
        m_[key] = l_.insert(l_.begin(), make_pair(key, ans));
        return ans;
    }

    void set(int key, int value) {
        if (m_.count(key) == 0) {
            m_[key] = l_.insert(l_.begin(), make_pair(key, value));
        } else {
            auto iter = m_[key];
            l_.erase(iter);
            m_[key] = l_.insert(l_.begin(), make_pair(key, value));
        }

        if (m_.size() > capacity_) {
            m_.erase(l_.back().first);
            l_.pop_back();
        }
    }

private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> l_;
};

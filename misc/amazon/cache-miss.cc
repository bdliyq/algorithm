// Question: Cache miss.

#include <vector>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int cache_miss(vector<int> array, int size) {
    list<int> l;
    map<int, list<int>::iterator> m;
    int count = 0;

    for (size_t i = 0; i < array.size(); ++i) {
        map<int, list<int>::iterator>::iterator it = m.find(array.at(i));
        if (it == m.end()) {
            m[array.at(i)] = l.insert(l.end(), array.at(i));
            if (l.size() > size) {
                m.erase(m.find(l.front()));
                l.erase(l.begin());
            }
            ++count;
        } else {
            l.erase(it->second);
            m[it->first] = l.insert(l.end(), *(it->second));
        }
    }

    return count;
}

int main(int argc, char** argv) {
    vector<int> array;
    array.push_back(4);
    array.push_back(4);
    array.push_back(3);
    array.push_back(2);
    array.push_back(5);
    array.push_back(6);
    array.push_back(4);

    int size = 4;
    int count = cache_miss(array, size);
    cout << count << endl;
    return 0;
}

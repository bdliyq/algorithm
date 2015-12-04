// Question: https://leetcode.com/problems/clone-graph/

#include "headers.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        stack<UndirectedGraphNode*> s;
        s.push(node);
        while (!s.empty()) {
            UndirectedGraphNode* n = s.top();
            s.pop();
            UndirectedGraphNode* n_copy = NULL;
            if (m.count(n) == 0) {
                n_copy = new UndirectedGraphNode(n->label);
                m[n] = n_copy;
            } else {
                n_copy = m[n];
            }

            for (auto nei : n->neighbors) {
                if (m.count(nei) == 0) {
                    UndirectedGraphNode* nei_copy = new UndirectedGraphNode(nei->label);
                    n_copy->neighbors.push_back(nei_copy);
                    s.push(nei);
                    m[nei] = nei_copy;
                } else {
                    n_copy->neighbors.push_back(m[nei]);
                }
            }
        }
        return m[node];
    }
};

int main(int argc, char** argv) {
    Solution s;
    UndirectedGraphNode* node = new UndirectedGraphNode(1);
    UndirectedGraphNode* copy = s.cloneGraph(node);
}

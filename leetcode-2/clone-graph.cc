// Question: https://leetcode.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
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
            auto n = s.top();
            s.pop();
            if (m.count(n) == 0) {
                m[n] = new UndirectedGraphNode(n->label);
            }
            auto newn = m[n];

            for (auto nei : n->neighbors) {
                if (m.count(nei) == 0) {
                    m[nei] = new UndirectedGraphNode(nei->label);
                    s.push(nei);
                }
                newn->neighbors.push_back(m[nei]);
            }
        }
        return m[node];
    }


};

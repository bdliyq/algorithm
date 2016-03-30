// Question: 克隆有向图。

struct GraphNode {
    int val;
    vector<GraphNode*> neighbors;
    GraphNode(int x) : val(x) {}
};

typedef unordered_set<GraphNode*> DirectedGraph;

// non recursion.
DirectedGraph clone(DirectedGraph& g) {
    DirectedGraph ans;
    unordered_map<GraphNode*, GraphNode*> m;
    queue<GraphNode*> q;
    for (auto node : g) {
        q.push(node);
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (m.count(node) == 0) {
            m[node] = new GraphNode(node->val);
        }

        auto new_node = m[node];
        for (auto nei : node->neighbors) {
            if (m.count(nei) == 0) {
                q.push(nei);
                m[nei] = new GraphNode(nei->val);
            }
            new_node->neighbors.push_back(m[nei]);
        }

        ans.insert(new_node);
    }

    return ans;
}

// recursion.
DirectedGraph clone(DirectedGraph& g) {
    DirectedGraph ans;
    unordered_map<GraphNode*, GraphNode*> m;
    for (auto node : g) {
        ans.insert(bfs(node, m));
    }
    return ans;
}

GraphNode* bfs(GraphNode* node, unordered_map<GraphNode*, GraphNode*>& m) {
    if (m.count(node) > 0) {
        return m[node];
    }
    m[node] = new GraphNode(node->val);

    auto newnode = m[node];
    for (auto nei : node->neighbors) {
        newnode->neighbors.push_back(bfs(nei, m));
    }
    return newnode;
}

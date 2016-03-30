// Question: Longest common suffix of two linked list.

vector<int> solve(ListNode* a, ListNode* b) {
    vector<ListNode*> va;
    vector<ListNode*> vb;

    auto node = a;
    while (node) {
        va.push_back(node);
    }
    node = b;
    while (node) {
        vb.push_back(node);
    }

    int i = (int)lena.size() - 1;
    int j = (int)lenb.size() - 1;

    vector<int> ans;
    while (i >= 0 && j >= 0) {
        if (va[i]->val == vb[j]->val) {
            ans.push_back(va[i]->val);
        } else {
            break;
        }
    }

    return ans;
}

// Question: int数组，有重复，给定一个minimal distance，要求重复的元素距离不能小于该distance。如果不能满足要求，则返回false。

#include "headers.h"

bool solve(vector<int>& nums, int dist) {
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());

    vector<int> cursors;
    for (int i = 0; i < nums.size(); i += dist) {
        cursors.push_back(i);
    }

    int i = 0;
    while (i < nums.size()) {
        for (int j = 0; j < cursors.size(); ++j) {
            if (i >= nums.size()) {
                break;
            }

            int idx = cursors[j];
            if (idx >= nums.size()) {
                continue;
            }

            if (idx % dist != 0 && nums[idx-1] == v[i]) {
                return false;
            }

            nums[idx] = v[i];
            ++i;
            cursors[j]++;
        }
    }
}

int main(int argc, char** argv) {
    vector<int> nums{1,2,2,3,1,1,1,1};
    bool ans = solve(nums, 2);
    cout << (ans ? "true" : "false") << endl;
    for (auto n : nums) {
        cout << n << " ";
    }
}




public String reArrangeChar(String str, int k) {
                if (str == null || str.length() == 0) {
                        return str;
                }

                int len = str.length();

                //count the freq of every char
                Map<Character, Node> map = new HashMap<>();
                for (int i = 0; i < str.length(); i++) {
                        char c = str.charAt(i);
                        if (!map.containsKey(c)) {
                                Node temp = new Node(c);
                                temp.freq++;
                                map.put(c, temp);
                        } else {
                                map.get(c).freq++;
                        }
                }

                //Put them into Heap
                Queue<Node> heap = new PriorityQueue<Node>(10, new MyComparator());
                for (Node node : map.values()) {
                        heap.offer(node);
                }

                StringBuilder sb = new StringBuilder();
                Queue<Node> q = new LinkedList<>();
                for (int currIndex = 0; currIndex < len; currIndex++) {
                        if (!q.isEmpty() && q.peek().lastPos + k < currIndex) {
                                heap.offer(q.poll());
                        }
                        
                        if (heap.isEmpty()) {
                                return "Not Valid";
                        }
                        
                        Node curr = heap.poll();
                        curr.lastPos = currIndex;
                        curr.freq--;
                        
                        sb.append(curr.c);
                        
                        if (curr.freq != 0) q.offer(curr);
                }
                return sb.toString();
                
        }
        class Node {
                char c;
                int freq;
                int lastPos;

                public Node(char c) {
                        this.c = c;
                }
        }

        class MyComparator implements Comparator<Node> {
                public int compare(Node one, Node two) {
                        if (one.freq != two.freq) {
                                return one.freq > two.freq ? -1 : 1;
                        }
                        return one.c - two.c;
                }
        }

// Question: https://leetcode.com/problems/anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string scopy = s;
            sort(scopy.begin(), scopy.end());
            m[scopy].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto item : m) {
            sort(item.second.begin(), item.second.end());
            ans.push_back(item.second);
        }
        return ans;
    }
};

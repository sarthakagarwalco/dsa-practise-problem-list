#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        
        for (const auto& item : items1) {
            mp[item[0]] += item[1];
        }
        
        for (const auto& item : items2) {
            mp[item[0]] += item[1];
        }
        
        vector<vector<int>> res;
        for (const auto& p : mp) {
            res.push_back({p.first, p.second});
        }
        
        return res;
    }
};
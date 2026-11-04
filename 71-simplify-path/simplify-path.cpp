#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string dir;
        
        while (getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(dir);
            }
        }
        
        string res = "";
        for (const string& s : st) {
            res += "/" + s;
        }
        
        return res.empty() ? "/" : res;
    }
};
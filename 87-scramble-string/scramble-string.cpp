#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    int dp[30][30][31];
    string a, b;

    bool solve(int i, int j, int len) {
        if (dp[i][j][len] != -1) {
            return dp[i][j][len];
        }
        if (len == 1) {
            return dp[i][j][len] = (a[i] == b[j]);
        }

        int cnt[26] = {0};
        for (int k = 0; k < len; ++k) {
            cnt[a[i + k] - 'a']++;
            cnt[b[j + k] - 'a']--;
        }
        for (int k = 0; k < 26; ++k) {
            if (cnt[k] != 0) {
                return dp[i][j][len] = 0;
            }
        }

        for (int k = 1; k < len; ++k) {
            if (solve(i, j, k) && solve(i + k, j + k, len - k)) {
                return dp[i][j][len] = 1;
            }
            if (solve(i, j + len - k, k) && solve(i + k, j, len - k)) {
                return dp[i][j][len] = 1;
            }
        }

        return dp[i][j][len] = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        a = s1;
        b = s2;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1.size());
    }
};
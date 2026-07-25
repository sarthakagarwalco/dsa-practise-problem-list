#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs for i nodes
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1;
        dp[1] = 1;
        
        // Build the dp array from 2 up to n
        for (int i = 2; i <= n; i++) {
            // Consider each number j from 1 to i as the root
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
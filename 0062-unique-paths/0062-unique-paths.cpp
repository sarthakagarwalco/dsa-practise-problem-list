class Solution {
public:
    int all_paths(int n, int m, vector<vector<int>> &dp){
        for (int i=0; i<=n; i++){
            for (int j=0; j<=m; j++){
                
                if (i==0 && j==0){
                    dp[i][j] = 1;
                }
                else {
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    int up = (i > 0) ? dp[i-1][j] : 0;

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[n][m];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return all_paths(m-1, n-1, dp);
    }
};
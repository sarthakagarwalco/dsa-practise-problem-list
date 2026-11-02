#include <vector>

using namespace std;

class Solution {
    int countLessEqual(const vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int r = n - 1;
        int c = 0;
        int cnt = 0;
        
        while (r >= 0 && c < n) {
            if (matrix[r][c] <= target) {
                cnt += r + 1;
                c++;
            } else {
                r--;
            }
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(matrix, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
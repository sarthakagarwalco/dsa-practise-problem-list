#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums2[i] < nums2[j];
        });
        
        vector<int> res(n);
        int l = 0, r = n - 1;
        
        for (int x : nums1) {
            if (x > nums2[idx[l]]) {
                res[idx[l]] = x;
                l++;
            } else {
                res[idx[r]] = x;
                r--;
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int house_robber(vector<int> &arr, int n){
        int prev2 = 0;
        int prev1 = arr[0];

        for (int i=1; i<n; i++){
            int take = -1;
            if (i > 0) take = arr[i] + prev2;
            else take = arr[i];

            int skip = prev1;
            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return house_robber(nums, n);
    }
};
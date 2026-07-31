#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Pointer for the next valid element's position
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place the valid element at the front
                k++;               // Increment the count/insertion pointer
            }
        }
        
        return k; // k is now the length of the array without 'val'
    }
};
class Solution {
public:
    int pi(vector<int>&nums){
        int n=nums.size();
        int s=0;int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[mid+1])return mid;
            else if(nums[mid]>nums[e])s=mid+1;
            else if(nums[mid]<nums[e])e=mid;
            else e--;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int idx=pi(nums);
        if(idx==-1)return nums[0];
        return nums[idx+1];
    }
};
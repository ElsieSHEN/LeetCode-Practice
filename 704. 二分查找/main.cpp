class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target) return pivot;
            if (nums[pivot] < target) left = pivot + 1;
            else right = pivot - 1;
        } return -1;
    }
};
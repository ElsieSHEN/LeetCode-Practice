class Solution {
private:
    void merge(vector<int>& nums, int lo, int mid, int hi) {
        int n1 = mid - lo + 1;
        int n2 = hi - mid;
        vector<int> left(n1), right(n2);
        for (int i=0; i<n1; i++) {left[i] = nums[lo+i];}
        for (int j=0; j<n2; j++) {right[j] = nums[mid+j+1];}
        left.push_back(60000);
        right.push_back(60000);
        int i, j = 0;
        for (int k=lo; k<=hi; k++) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
        }
    }

    // take merge sort as 二叉树的后序遍历
    void mergeSort(vector<int>& nums, int lo, int hi) {
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            mergeSort(nums, lo, mid);
            mergeSort(nums, mid+1, hi);
            merge(nums, lo, mid, hi);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
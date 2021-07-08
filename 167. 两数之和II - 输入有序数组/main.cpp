/* 双指针 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left+1, right+1};
            else if (sum < target) left ++;
            else right --;
        }
        return {-1, -1};
    }
};

/* 二分查找 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i=0; i<n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] + numbers[i] == target) return {i+1, mid+1};
                else if (numbers[mid] + numbers[i] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return {-1, -1};
    }
};
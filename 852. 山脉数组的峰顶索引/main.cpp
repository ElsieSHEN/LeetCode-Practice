class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            if (arr[i] > arr[i+1]) {
                start = i;
                break;
            }
        }
        return start;
    }
};

/* 二分查找 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 1, right = n - 2, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1]) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
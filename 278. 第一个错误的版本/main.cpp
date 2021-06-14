// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid) == true) {
                end = mid; // 后面的都不用看了
            } else {
                start = mid + 1; // 前面的都不用看了
            }
        } // when start = end
        return start;
    }        
};
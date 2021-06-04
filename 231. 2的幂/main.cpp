class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 0) {
            if (n == 1) return true;
            if (n % 2 == 0) n = n / 2;
            else return false;
        }
        return false;
    }
};

// 关联题目：342. 4的幂

/* 位运算 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
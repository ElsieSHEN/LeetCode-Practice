class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n > 0) {
            if (n == 1) return true;
            if (n % 4 == 0) n = n / 4;
            else return false;
        }
        return false;
    }
};

/*如果 n 是 4 的幂，那么 n 一定也是 2 的幂。
 *因此我们可以首先判断 n 是否是 2 的幂，
 *在此基础上再判断 n 是否是 4 的幂。
 */


class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
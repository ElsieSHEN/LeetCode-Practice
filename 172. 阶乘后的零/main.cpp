class Solution {
public:
    int trailingZeroes(int n) {
        // min((count(2,5)))
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
};
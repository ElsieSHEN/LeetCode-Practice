/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while (start < end) {
            int pick = start + (end - start) / 2;
            if (guess(pick) == 1) start = pick + 1;
            if (guess(pick) <= 0) end = pick;
        }
        return start;
    } 
};
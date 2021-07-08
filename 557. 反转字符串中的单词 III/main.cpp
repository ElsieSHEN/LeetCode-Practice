/* 双指针 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        string result;
        for (int idx=0; idx<n; idx++) {
            if (s[idx] == ' ') {
                int m = idx - start;
                string word = s.substr(start, m);
                result.append(reWord(word)); 
                result = result + ' ';
                start = idx + 1;
                }
            else if (idx == n-1) {
                string word = s.substr(start);
                result.append(reWord(word));
            }
            }
        return result;
    }
    
    string reWord(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left ++;
            right --;
        }
        return s;
    }
};
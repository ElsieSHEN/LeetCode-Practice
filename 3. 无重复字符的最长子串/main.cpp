class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxLen = 0;
        int start = 0;
        for (int i=0; i<s.size(); i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[start]);
                start ++;
            }
            maxLen = max(maxLen, i-start+1);
            lookup.insert(s[i]);
        }
        return maxLen;
    }
};

/* 滑动窗口 */
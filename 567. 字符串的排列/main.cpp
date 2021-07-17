class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> cnt(26);
        for (int i=0; i<n; i++) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }
        int diff = 0;
        for (int c: cnt) {
            if (c != 0) diff++;
        }
        if (diff == 0) return true;
        for (int i=n; i<m; i++) {
            int x = s2[i] - 'a';
            int y = s2[i-n] - 'a';
            if (x == y) continue;
            if (cnt[x] == 0) diff++;
            cnt[x]++;
            if (cnt[x] == 0) diff--;
            if (cnt[y] == 0) diff++;
            cnt[y]--;
            if (cnt[y] == 0) diff--;
            if (diff == 0) return true;
        }
        return false;
    }
};
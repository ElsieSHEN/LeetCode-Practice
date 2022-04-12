class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (auto & c : s) {
            int temp = widths[c - 'a']; // 当前字母所需要的长度
            width += temp;
            if (width > 100) { //如果加上该字母使得该行总长度>100，则将该字母放到下一行
                lines++;
                width = temp;
            }
        }
        return {lines, width};
    }
};
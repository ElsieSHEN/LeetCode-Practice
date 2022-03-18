class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();
        if (image[x][y] == color) {
            image[x][y] = newColor;
            for (int i=0; i<4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if (mx >= 0 && mx < n && my >=0 && my < m) {
                    dfs(image, mx, my, color, newColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int curCorlor = image[sr][sc];
        if (curCorlor != newColor) {
            dfs(image, sr, sc, curCorlor, newColor);
        }
        return image;
    }
};
class Solution {
public:
    vector<vector<int>>reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = y; i < y + k; i++) {
            int top = x;
            int bottom = x + k - 1;
            while (top < bottom) {
                swap(grid[top][i], grid[bottom][i]);
                top++;
                bottom--;
            }
        }
        return grid;
    }
};
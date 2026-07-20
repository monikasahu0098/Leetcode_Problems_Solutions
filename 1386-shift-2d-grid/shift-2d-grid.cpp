class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        int n=r*c;

        k=k%n;
        if(!k){
            return grid;
        }

        auto shift=[&](int a,int b){
            while(a<b){
                swap(grid[a/c][a%c],grid[b/c][b%c]);
                a++;
                b--;
            }
        };
        shift(0,n-1);
        shift(0,k-1);
        shift(k,n-1);

        return grid;
    }
};
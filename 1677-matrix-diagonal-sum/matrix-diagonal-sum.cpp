class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int lSum=0;
        int i=0;
        int j=0;

        while(i<m && j<n){
            lSum+=mat[i][j];
            i++;
            j++;
        }

        int rSum=0;
        int x=0;
        int y=n-1;
        while(x<m && y>=0){
            if(x != y){
                rSum+=mat[x][y];
            }
            x++;
            y--; 
        }

        return lSum+rSum;
    }
};